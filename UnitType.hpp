#pragma once
#include "Unit.hpp"

class UnitType {
public:
  const int price, initialHp, attackDamage;
  UnitType(int price, int initialHp, int attackDamage);
  virtual void resolveAttack(Unit& u) const = 0;
  virtual void promote(Unit& u) const = 0;
};
