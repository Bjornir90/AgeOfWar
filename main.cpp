#include <iostream>
#include "Player.hpp"
#include "ArtificialIntelligence.hpp"
#include "Human.hpp"
#include "Battlefield.hpp"
#include "Archer.hpp"

const int STARTING_MONEY = 4, STARTING_HP = 100;
Player *player0, *player1;
Battlefield *bf;

void startGame(bool isAI0, bool isAI1){
    bf = new Battlefield();
    if(isAI0){
        ArtificialIntelligence *AI0 = new ArtificialIntelligence(STARTING_MONEY, STARTING_HP, bf->leftAccess);
        player0 = AI0;
    } else {
        Human *human0 = new Human(STARTING_MONEY, STARTING_HP, bf->leftAccess);
        player0 = human0;
    }
    if(isAI1){
        ArtificialIntelligence *AI1 = new ArtificialIntelligence(STARTING_MONEY, STARTING_HP, bf->rightAccess);
        player1 = AI1;
    } else {
        Human *human1 = new Human(STARTING_MONEY, STARTING_HP, bf->rightAccess);
        player1 = human1;
    }
}



int main() {
    Archer *archer = new Archer();
    std::cout<<archer->generateSaveString()<<std::endl;
    return 0;
}