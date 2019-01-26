#pragma once

#include <string>
#include "Unit.fwd.hpp"
#include "Battlefield.hpp"
#include "Hurtable.hpp"

class UnitType {
public:
  const int price, initialHp, attackDamage;
  UnitType(int price, int initialHp, int attackDamage);
  //return true if the unit has used all its remaining attack for the turn
  virtual bool resolveAttack(Unit &u) const = 0;
  virtual void promote(Unit& u) const = 0;
  virtual std::string name() const = 0;
  virtual std::string generateSaveString() const = 0;
  void printAttackMove(std::string attackerName, Hurtable* defender) const;
};
