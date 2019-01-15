#pragma once
#include "UnitType.hpp"

class Archer : public UnitType {
public:
  Archer();
  static const Archer instance;
  void resolveAttack(Unit& u) const;
};
