#include "SuperSoldier.hpp"

const SuperSoldier SuperSoldier::instance = SuperSoldier();

void SuperSoldier::resolveAttack(Unit& u) const {
  u.owner.getMoney() + 0; // dummy code, to avoid "u not used" at compilation
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
