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
        toBuy = new Catapult();
    } else if(currentMoney >= 12){//buy archer
        toBuy = new Archer();
    } else if(currentMoney >= 10){//buy soldier
        toBuy = new Soldier();
    } else {
        printf("Trolol tu es pauvre");
        toBuy = nullptr;
    }
    return toBuy;
}

ArtificialIntelligence::ArtificialIntelligence(int money, int team, int hp) : Player(money, team, hp) {}
