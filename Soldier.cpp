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
    Hurtable* unitInCell = bf.getEnnemy(u.position+1);
    if(unitInCell == nullptr) return false;
    reward = unitInCell->hurt(attackDamage);
    printAttackMove("Soldier", unitInCell);
    u.owner.addRewardMoney(reward);
    return true;
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
