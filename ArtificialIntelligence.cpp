//
// Created by bjornir on 09/01/19.
//

#include <cstdio>
#include "ArtificialIntelligence.hpp"
#include "Catapult.hpp"
#include "Archer.hpp"
#include "Soldier.hpp"

Unit * ArtificialIntelligence::getNextBuy(){
    int currentMoney = this->getMoney();
    Unit * toBuy;
    if(currentMoney >= 20){//buy catapult
        toBuy = new Unit(&Catapult::instance, *this);
    } else if(currentMoney >= 12){//buy archer
        toBuy = new Unit(&Archer::instance, *this);
    } else if(currentMoney >= 10){//buy soldier
        toBuy = new Unit(&Soldier::instance, *this);
    } else {
        return nullptr;
    }
    this->spendMoney(toBuy->type->price);
    return toBuy;
}

ArtificialIntelligence::ArtificialIntelligence(
  int money, int hp, int side, BattlefieldAccessor& bf) : Player(money, hp, side, bf) {}
