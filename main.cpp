#include <iostream>
#include "Player.hpp"
#include "ArtificialIntelligence.hpp"
#include "Human.hpp"
#include "Battlefield.hpp"
#include "Archer.hpp"
#include "Soldier.hpp"
#include "Unit.hpp"

const int STARTING_MONEY = 4, STARTING_HP = 100;
Player *player0, *player1;
Battlefield bf;

void startGame(bool isAI0, bool isAI1){
    if(isAI0)
        player0 = new ArtificialIntelligence(STARTING_MONEY, STARTING_HP, 0, bf.leftAccess);
    else
        player0 = new Human(STARTING_MONEY, STARTING_HP, 0, bf.leftAccess);

    if(isAI1)
        player1 = new ArtificialIntelligence(STARTING_MONEY, STARTING_HP, 1, bf.rightAccess);
    else
        player1 = new Human(STARTING_MONEY, STARTING_HP, 1, bf.rightAccess);

    bf.setPlayers(player0, player1);
}

Player *loadPlayer(std::ifstream &savedFile, bool isLeft){
    int filePosition = 0, savedMoney = -1, savedHp = -1, savedIsAi = -1;
    std::string line;
    Player *loadedPlayer;
    while (std::getline(savedFile, line)) {
        switch (filePosition) {
            //money is first in the file
            case 0:
                filePosition++;
                savedMoney = std::stoi(line);
                break;
            //hp is second
            case 1:
                filePosition++;
                savedHp = std::stoi(line);
                break;
            //and then we check if the player was an AI or not
            case 2:
                savedIsAi = std::stoi(line);
                    if(savedIsAi == 0) {
                        loadedPlayer = new Human(savedMoney, savedHp, (isLeft)?0:1, (isLeft)?(BattlefieldAccessor&)bf.leftAccess:(BattlefieldAccessor&)bf.rightAccess);
                    } else {
                        loadedPlayer = new ArtificialIntelligence(savedMoney, savedHp, (isLeft)?0:1, (isLeft)?(BattlefieldAccessor&)bf.leftAccess:(BattlefieldAccessor&)bf.rightAccess);
                    }
                return loadedPlayer;
        }
    }
}

void loadGame(std::string fileName){
    std::ifstream savedFile(fileName);
    bool hasLoadedPlayers = false;
    while(!savedFile.eof()){
        if(!hasLoadedPlayers){
            hasLoadedPlayers = true;
            //first we have to load the players, so we can set them in units
            player0 = loadPlayer(savedFile, true);
            player1 = loadPlayer(savedFile, false);
            bf.setPlayers(player0, player1);
        }
        //we load every units from the stream, with the just loaded players
        Unit::loadFromStream(savedFile, player0, player1);
    }
    bf.print(std::cout);
}

void savePlayer(Player *player, std::ofstream &saveFile){
    saveFile<<std::to_string(player->getMoney())+"\n"+std::to_string(player->base.getHp())+"\n"+((player->isAI())?"1":"0")+"\n";
}

//Save the whole game
void saveGame(){
    std::ofstream saveFile("save.aow");
    //save the players
    savePlayer(player0, saveFile);
    savePlayer(player1, saveFile);
    //save every units
    for(int unitIndex = 0; unitIndex<BF_SIZE; unitIndex++){
        Unit * currentUnit = bf.leftAccess[unitIndex];
        if(currentUnit == nullptr) continue;
        saveFile<<currentUnit->generateSaveString();
    }
    saveFile.close();
}

void promptForSave(){
    std::cout<<"Voulez vous charger, sauvegarder ou ne rien faire (s:c:r)?"<<std::endl;
    std::string response;
    while(true){
        std::cin>>response;
        if(response == "s"){
            saveGame();
            return;
        } else if(response == "c"){
            loadGame("save.aow");
            return;
        } else if(response == "r"){
            return;
        } else {
            std::cout<<"Entrée invalide, merci de répondre à nouveau :"<<std::endl;
        }
    }
}

void runTurn(){
    //money for each turn
    player0->addRewardMoney(8);
    player1->addRewardMoney(8);

    bf.print(std::cout);

    //Reset all units turn
    for(int unitIndex = 0; unitIndex<BF_SIZE; unitIndex++){
        Unit * currentUnit = bf.leftAccess[unitIndex];
        if(currentUnit == nullptr) continue;
        currentUnit->newTurn();
    }

    //player0 (left) units attack
    std::cout << std::endl << Color(P0_COLOR);
    for(int index = 0; index<BF_SIZE; index++){
        Unit *currentUnit = bf.leftAccess[index];
        if(currentUnit == nullptr) continue;
        //Stop at the first ennemy unit
        if(!(currentUnit->owner == *player0)) break;
        currentUnit->resolveAttack();
    }

    //player0 (left) units moves, then attacks, if they didn't the first time
    for(int index = BF_SIZE-1; index>=0; index--) {
        Unit *currentUnit = bf.leftAccess[index];
        if(currentUnit == nullptr) continue;
        if (currentUnit->owner == *player0) {//So other player units do not advance
            if (bf.leftAccess.moveFwd(currentUnit->position)) {
                currentUnit->position++;
            }
            currentUnit->resolveAttack();
        }
    }

    //player1 (right) units attack
    std::cout << Color(P1_COLOR);
    for(int index = 0; index<BF_SIZE; index++){
        Unit *currentUnit = bf.rightAccess[index];
        if(currentUnit == nullptr) continue;
        //Stop at the first ennemy unit
        if(!(currentUnit->owner == *player1)) break;
        currentUnit->resolveAttack();
    }

    //player1 (right) units moves, then attacks, if they didn't the first time
    for(int index = BF_SIZE-1; index>=0; index--) {
        Unit *currentUnit = bf.rightAccess[index];
        if(currentUnit == nullptr) continue;
        if (currentUnit->owner == *player1) {//So other player units do not advance
            if (bf.rightAccess.moveFwd(currentUnit->position)) {
                currentUnit->position++;
            }
            currentUnit->resolveAttack();
        }
    }

    std::cout << Color::reset << std::endl;
    promptForSave();

    if(bf.leftAccess[0] == nullptr){
        std::cout << std::endl << Color(P0_COLOR) << "[Player1] ";
        std::cout.flush();
        bf.leftAccess[0] = player0->getNextBuy();
        std::cout << Color::reset;
    }

    if(bf.rightAccess[0] == nullptr){
        std::cout << std::endl << Color(P1_COLOR) << "[Player2] ";
        std::cout.flush();
        bf.rightAccess[0] = player1->getNextBuy();
        std::cout << Color::reset;
    }

    std::cout << std::endl;
    for(unsigned short i = 0; i < BF_SIZE*(BF_DISP_WIDTH+1)+1; i++) std::cout << '=';
    std::cout << std::endl << std::endl;

}


int main() {
    startGame(false, true);
    for(int i = 0; i<500; i++){
        runTurn();
        if(player0->base.getHp() <= 0) {
          std::cout << std::endl << Color(P1_COLOR, "Player 2 wins !") << std::endl;
          return 0;
        }
        else if(player1->base.getHp() <= 0) {
          std::cout << std::endl << Color(P0_COLOR, "Player 1 wins !") << std::endl;
          return 0;
        }
    }
    return 0;
}
