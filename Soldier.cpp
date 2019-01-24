//
// Created by bjornir on 09/01/19.
//

#include "Soldier.hpp"
#include "SuperSoldier.hpp"
#include "Player.hpp"

const Soldier Soldier::instance = Soldier();

bool Soldier::resolveAttack(Unit &u) const {
    BattlefieldAccessor &bf = u.owner.getBf();
    int reward = 0;
    Unit * unitInCell = bf[u.position+1];
    if(unitInCell == nullptr) return false;
    if(unitInCell->owner != u.owner){
        reward = unitInCell->hurt(attackDamage);
        u.owner.addRewardMoney(reward);
        return true;
    }
    return false;
}

void Soldier::promote(Unit &u) const {
    u.type = &SuperSoldier::instance;
}

std::string Soldier::name() const {
    return "Soldier";
}

std::string Soldier::generateSaveString() const {
    std::string save = "soldier";
    return save;
}
