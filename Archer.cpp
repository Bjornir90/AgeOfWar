#include "Archer.hpp"

const Archer Archer::instance = Archer();

void Archer::resolveAttack(Unit &u) const {
    BattlefieldAccessor &bf = u.owner.getBf();
    int reward = 0;
    for(int i = u.position+1; i <= u.position+3; i++){
        Unit * unitInCell = bf[i];
        if(unitInCell == nullptr) continue;
        reward = unitInCell->hurt(3);
        u.owner.addRewardMoney(reward);
        return;
    }
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
