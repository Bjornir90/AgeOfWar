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
        player0 = new ArtificialIntelligence(STARTING_MONEY, STARTING_HP, bf.leftAccess);
    else
        player0 = new Human(STARTING_MONEY, STARTING_HP, bf.leftAccess);

    if(isAI1)
        player1 = new ArtificialIntelligence(STARTING_MONEY, STARTING_HP, bf.rightAccess);
    else
        player1 = new Human(STARTING_MONEY, STARTING_HP, bf.rightAccess);

    bf.setPlayers(player0, player1);
}

void runTurn(){
    //money for each turn
    player0->addRewardMoney(8);
    player1->addRewardMoney(8);

    for(int index = 0; index<BF_SIZE; index++){
        Unit *currentUnit = bf.leftAccess[index];
        //Stop at the first ennemy unit
        if(!(currentUnit->owner == *player0)) break;
        currentUnit->resolveAttack();
    }

    for(int index = BF_SIZE-1; index>=0; index--) {
        Unit *currentUnit = bf.leftAccess[index];
        if (currentUnit->owner == *player0) {//So other player units do not advance
            if (bf.leftAccess.moveFwd(currentUnit->position)) {
                currentUnit->position++;//TODO add a method in battlefield so the unit actually reproduce the same movement
            }
            currentUnit->resolveAttack();//TODO check if the unit already attacked (probably add a method in unitType canAttack() to handle all different cases)
        }
    }

    for(int index = 0; index<BF_SIZE; index++){
        Unit *currentUnit = bf.rightAccess[index];
        //Stop at the first ennemy unit
        if(!(currentUnit->owner == *player1)) break;
        currentUnit->resolveAttack();
    }

    for(int index = BF_SIZE-1; index>=0; index--) {
        Unit *currentUnit = bf.rightAccess[index];
        if (currentUnit->owner == *player1) {//So other player units do not advance
            if (bf.rightAccess.moveFwd(currentUnit->position)) {
                currentUnit->position++;//TODO add a method in battlefield so the unit actually reproduce the same movement
            }
            currentUnit->resolveAttack();//TODO check if the unit already attacked (probably add a method in unitType canAttack() to handle all different cases)
        }
    }

    if(bf.leftAccess[0] != nullptr){
        bf.leftAccess[0] = player0->getNextBuy();
    }

    if(bf.rightAccess[0] != nullptr){
        bf.rightAccess[0] = player1->getNextBuy();
    }
}

int main() {
    startGame(false, true);
    bf.leftAccess[0] = new Unit(&(Archer::instance), *player0);
    bf.rightAccess[0] = new Unit(&(Soldier::instance), *player1);
    bf.print(std::cout);
    std::cout << bf.leftAccess[0]->generateSaveString() << std::endl;
    return 0;
}
