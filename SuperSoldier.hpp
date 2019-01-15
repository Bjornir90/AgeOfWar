#pragma once
#include "UnitType.hpp"

class SuperSoldier : public UnitType {
public:
  SuperSoldier();
  static const SuperSoldier instance;
  void resolveAttack(Unit& u) const;
};
