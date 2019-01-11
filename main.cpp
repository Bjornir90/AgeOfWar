#include <iostream>
#include "Player.hpp"
#include "ArtificialIntelligence.hpp"
#include "Human.hpp"

const int STARTING_MONEY = 4, STARTING_HP = 100;
Player *player0, *player1;

void startGame(bool isAI0, bool isAI1){
    if(isAI0){
        ArtificialIntelligence *AI0 = new ArtificialIntelligence(STARTING_MONEY, 0, STARTING_HP);
        player0 = AI0;
    } else {
        Human *human0 = new Human(STARTING_MONEY, 0, STARTING_HP);
        player0 = human0;
    }
    if(isAI1){
        ArtificialIntelligence *AI1 = new ArtificialIntelligence(STARTING_MONEY, 1, STARTING_HP);
        player1 = AI1;
    } else {
        Human *human1 = new Human(STARTING_MONEY, 1, STARTING_HP);
        player1 = human1;
    }
}



int main() {
    Human human(STARTING_MONEY, 0, STARTING_HP);
    Unit *nextBuy = human.getNextBuy();
    std::cout<<"HP :"<<nextBuy->getHp()<<std::endl;
    return 0;
}