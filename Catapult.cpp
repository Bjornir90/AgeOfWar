//
// Created by bjornir on 09/01/19.
//

#include "Catapult.hpp"
#include "Battlefield.hpp"
#include "Unit.hpp"

const Catapult Catapult::instance = Catapult();

bool Catapult::resolveAttack(Unit &u) const {
    BattlefieldAccessor &bf = u.owner.getBf();
    int reward = 0;
    for(int i = u.position+2; i < BF_SIZE && i <= u.position+4 ; i++) {
        Hurtable* unitInCell = bf.getEnnemy(i);
        if (unitInCell == nullptr) continue;
        //Catapult can not move after having attacked
        u.canMove = false;
        //Get the other target of the catapult, if the main target is at max range, then the other target is the unit closer to the catapult
        Hurtable* otherTarget = (i == u.position + 4 || i==BF_SIZE-1) ? bf.getEnnemy(i - 1) : bf.getEnnemy(i + 1);
        reward = unitInCell->hurt(attackDamage);
        printAttackMove("Catapult", unitInCell);
        //Add a reward both for friendly and ennemy units killed
        if(otherTarget != nullptr) {
            reward += otherTarget->hurt(attackDamage);
            printAttackMove("Catapult", otherTarget);
        }
        u.owner.addRewardMoney(reward);
        return true;
    }
    //return true, even if the catapult hasn't attacked, so it isn't trying to attack a second time
    return true;
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
