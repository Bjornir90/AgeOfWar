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
    if(currentMoney >= 20){//buy catapult
        Catapult catapult();
    } else if(currentMoney >= 12){//buy archer
        Archer archer();
    } else if(currentMoney >= 10){//buy soldier
        Soldier soldier();
    } else {
        printf("Trolol tu es pauvre");
    }
}

ArtificialIntelligence::ArtificialIntelligence(int money, int team, int hp) : Player(money, team, hp) {}
