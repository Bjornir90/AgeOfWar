#pragma once
#include "Unit.hpp"

class UnitType {
public:
  const int price, initialHp;
  UnitType(int price, int initialHp);
  virtual void resolveAttack(Unit& u) const = 0;
};
