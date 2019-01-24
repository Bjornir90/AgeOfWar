//
// Created by bjornir on 09/01/19.
//

#include "Catapult.hpp"
#include "Battlefield.hpp"
#include "Unit.hpp"

const Catapult Catapult::instance = Catapult();

void Catapult::resolveAttack() {

}

bool Catapult::resolveAttack(Unit &u) const {
    BattlefieldAccessor &bf = u.owner.getBf();
    int reward = 0;
    for(int i = u.position+2; i <= u.position+4; i++){
        Unit * unitInCell = bf[i];
        if (unitInCell == nullptr) continue;
        if(unitInCell->owner != u.owner) {
            //Get the other target of the catapult, if the main target is at max range, then the other target is the unit closer to the catapult
            Unit *otherTarget = (i == u.position + 4) ? bf[i - 1] : bf[i + 1];
            reward = unitInCell->hurt(attackDamage);
            //Might add a reward for friendly units killed, is it intended behavior ?
            reward += otherTarget->hurt(attackDamage);
            u.owner.addRewardMoney(reward);
            return true;
        }
    }
    return false;
}

void Catapult::promote(Unit &u) const {
    return;
}

std::string Catapult::name() const {
    return "Catapult";
}

std::string Catapult::generateSaveString() const{
    std::string save = "catapult";
    return save;
}

