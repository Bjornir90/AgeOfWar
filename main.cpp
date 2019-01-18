#include <iostream>
#include "Player.hpp"
#include "ArtificialIntelligence.hpp"
#include "Human.hpp"
#include "Battlefield.hpp"
#include "Archer.hpp"
#include "Soldier.hpp"

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



int main() {
    startGame(false, true);
    bf.leftAccess[0] = new Unit(&(Archer::instance), *player0);
    bf.rightAccess[0] = new Unit(&(Soldier::instance), *player1);
    bf.print(std::cout);
    std::cout << bf.leftAccess[0]->generateSaveString() << std::endl;
    return 0;
}
