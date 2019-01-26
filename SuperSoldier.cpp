#include "SuperSoldier.hpp"

const SuperSoldier SuperSoldier::instance = SuperSoldier();

//Actually the same as soldier, except we always return false
bool SuperSoldier::resolveAttack(Unit &u) const {
    BattlefieldAccessor &bf = u.owner.getBf();
    int reward = 0;
    Hurtable* unitInCell = bf.getEnnemy(u.position+1);
    if(unitInCell == nullptr) return false;
    reward = unitInCell->hurt(attackDamage);
    printAttackMove("Supersoldier", unitInCell);
    u.owner.addRewardMoney(reward);
    return false;
}

void SuperSoldier::promote(Unit &u) const {

}

std::string SuperSoldier::name() const {
    return "Super soldier";
}

std::string SuperSoldier::generateSaveString() const {
    std::string save = "supersoldier";
    return save;
}
