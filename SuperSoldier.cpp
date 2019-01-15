#include "SuperSoldier.hpp"

SuperSoldier::SuperSoldier() : UnitType(-1, 10) {}

const SuperSoldier SuperSoldier::instance = SuperSoldier();

void SuperSoldier::resolveAttack(Unit& u) const {
  u.owner.getMoney() + 0; // dummy code, to avoid "u not used" at compilation
}
