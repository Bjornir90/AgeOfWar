//
// Created by bjornir on 09/01/19.
//

#include <cstdio>
#include "ArtificialIntelligence.hpp"
#include "Catapult.hpp"
#include "Archer.hpp"
#include "Soldier.hpp"
#include <unistd.h>

Unit * ArtificialIntelligence::getNextBuy(){
    int currentMoney = this->getMoney();
    Unit * toBuy;
    sleep(1);
    if(currentMoney >= 20){//buy catapult
        toBuy = new Unit(&Catapult::instance, *this);
        std::cout << "Catapult" << std::endl;
    } else if(currentMoney >= 12){//buy archer
        toBuy = new Unit(&Archer::instance, *this);
        std::cout << "Archer" << std::endl;
    } else if(currentMoney >= 10){//buy soldier
        toBuy = new Unit(&Soldier::instance, *this);
        std::cout << "Soldier" << std::endl;
    } else {
        std::cout << "Nothing" << std::endl;
        return nullptr;
    }
    this->spendMoney(toBuy->type->price);
    return toBuy;
}

ArtificialIntelligence::ArtificialIntelligence(
  int money, int hp, int side, BattlefieldAccessor& bf) : Player(money, hp, side, bf) {}

bool ArtificialIntelligence::isAI() {
    return true;
}
