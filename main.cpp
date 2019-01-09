#include <iostream>
#include "Player.hpp"

const int STARTING_MONEY = 4, STARTING_HP = 100;

void startGame(bool activateAI){
    Player player0(STARTING_MONEY, 0, STARTING_HP), player1(STARTING_MONEY, 1, STARTING_HP);
    Player::addPlayer(player0, 0);
    Player::addPlayer(player1, 1);
    if(activateAI){

    }
}



int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}