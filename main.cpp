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

void runTurn(){
    //money for each turn
    player0->addRewardMoney(8);
    player1->addRewardMoney(8);

    //Reset all units turn
    for(int unitIndex = 0; unitIndex<BF_SIZE; unitIndex++){
        Unit * currentUnit = bf.leftAccess[unitIndex];
        if(currentUnit == nullptr) continue;
        currentUnit->newTurn();
    }

    for(int index = 0; index<BF_SIZE; index++){
        Unit *currentUnit = bf.leftAccess[index];
        if(currentUnit == nullptr) continue;
        //Stop at the first ennemy unit
        if(!(currentUnit->owner == *player0)) break;
        currentUnit->resolveAttack();
    }

    for(int index = BF_SIZE-1; index>=0; index--) {
        Unit *currentUnit = bf.leftAccess[index];
        if(currentUnit == nullptr) continue;
        if (currentUnit->owner == *player0) {//So other player units do not advance
            if (bf.leftAccess.moveFwd(currentUnit->position)) {
                currentUnit->position++;//TODO add a method in battlefield so the unit actually reproduce the same movement
            }
            currentUnit->resolveAttack();
        }
    }

    for(int index = 0; index<BF_SIZE; index++){
        Unit *currentUnit = bf.rightAccess[index];
        if(currentUnit == nullptr) continue;
        //Stop at the first ennemy unit
        if(!(currentUnit->owner == *player1)) break;
        currentUnit->resolveAttack();
    }

    for(int index = BF_SIZE-1; index>=0; index--) {
        Unit *currentUnit = bf.rightAccess[index];
        if(currentUnit == nullptr) continue;
        if (currentUnit->owner == *player1) {//So other player units do not advance
            if (bf.rightAccess.moveFwd(currentUnit->position)) {
                currentUnit->position++;//TODO add a method in battlefield so the unit actually reproduce the same movement
            }
            currentUnit->resolveAttack();
        }
    }

    if(bf.leftAccess[0] == nullptr){
        bf.leftAccess[0] = player0->getNextBuy();
    }

    if(bf.rightAccess[0] == nullptr){
        bf.rightAccess[0] = player1->getNextBuy();
    }

    bf.print(std::cout);
}

void loadGame(std::string fileName){
    std::ifstream savedFile(fileName);
    bool hasLoadedPlayers = false;
    while(!savedFile.eof()){
        if(!hasLoadedPlayers){
            std::string line;
            int filePosition = 0, savedMoney, savedHp, savedIsAi;
            for(int playerIndex = 0; playerIndex<2; playerIndex++) {
                while (std::getline(savedFile, line)) {
                    switch (filePosition) {
                        case 0:
                            filePosition++;
                            savedMoney = std::stoi(line);
                            break;
                        case 1:
                            filePosition++;
                            savedHp = std::stoi(line);
                            break;
                        case 2:
                            savedIsAi = std::stoi(line);
                            if(playerIndex == 0){
                                if(savedIsAi == 0) {
                                    player0 = new Human(savedMoney, savedHp, playerIndex, bf.leftAccess);
                                } else {
                                    player0 = new ArtificialIntelligence(savedMoney, savedHp, playerIndex, bf.leftAccess);
                                }
                            } else {
                                if(savedIsAi == 0) {
                                    player1 = new Human(savedMoney, savedHp, playerIndex, bf.rightAccess);
                                } else {
                                    player1 = new ArtificialIntelligence(savedMoney, savedHp, playerIndex, bf.rightAccess);
                                }
                            }
                            break;
                    }
                }
            }
            hasLoadedPlayers = true;
        }
        Unit::loadFromStream(savedFile, player0, player1);
    }
}

void savePlayer(Player *player, std::ofstream &saveFile){
    saveFile<<std::to_string(player->base.getHp())+"\n"+std::to_string(player->getMoney())+"\n"+((player->isAI())?"1":"0")+"\n";
}

void saveGame(){
    std::ofstream saveFile("save.aow");
    savePlayer(player0, saveFile);
    savePlayer(player1, saveFile);
    for(int unitIndex = 0; unitIndex<BF_SIZE; unitIndex++){
        Unit * currentUnit = bf.leftAccess[unitIndex];
        if(currentUnit == nullptr) continue;
        saveFile<<currentUnit->generateSaveString();
    }
}


int main() {
    startGame(false, true);
    for(int i = 0; i<500; i++){
        runTurn();
    }
    return 0;
}
