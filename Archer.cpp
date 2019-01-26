#include "Archer.hpp"

const Archer Archer::instance = Archer();

bool Archer::resolveAttack(Unit &u) const {
    BattlefieldAccessor &bf = u.owner.getBf();
    int reward = 0;
    for(int i = u.position+1; i < BF_SIZE && i <= u.position+3; i++) {
        Hurtable* unitInCell = bf.getEnnemy(i);
        if(unitInCell == nullptr) continue;
        reward = unitInCell->hurt(attackDamage);
        printAttackMove("Archer", unitInCell);
        u.owner.addRewardMoney(reward);
        return true;
    }
    return false;
}

void Archer::promote(Unit &u) const {
    return;
}

std::string Archer::name() const {
    return "Archer";
}

std::string Archer::generateSaveString() const {
    std::string save = "archer";
    return save;
}
