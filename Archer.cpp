//
// Created by bjornir on 09/01/19.
//

#include "Archer.hpp"

void Archer::resolveAttack() {
    BattlefieldAccessor &bf = *(owner->getBf());
    int reward = 0;
    for(int i = position+1; i<=position+3; i++){
        Unit * unitInCell = bf[i];
        if(unitInCell == nullptr) continue;
        reward = unitInCell->hurt(attackpower);
        owner->addRewardMoney(reward);
        return;
    }
}

