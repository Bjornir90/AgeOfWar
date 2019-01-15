#pragma once
#include "UnitType.hpp"

class SuperSoldier : public UnitType {
public:
  SuperSoldier() : UnitType(10, 10, 4);
  static const SuperSoldier instance;
  void resolveAttack(Unit& u) const;

    void promote(Unit &u) const override;

    std::string name() override;
};
