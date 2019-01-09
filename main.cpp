#include <iostream>
#include "Player.hpp"

const int STARTING_MONEY = 4, STARTING_HP = 100;

void startGame(){
    Player player0(STARTING_MONEY, 0, STARTING_HP), player1(STARTING_MONEY, 1, STARTING_HP);

}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}