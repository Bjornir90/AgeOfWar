//
// Created by bjornir on 09/01/19.
//

#include "Unit.hpp"
#include "UnitType.hpp"

int Unit::getHp() const {
    return hp;
}

int Unit::hurt(int damage){
    hp -= damage;
    if(hp <= 0) return type->price/2;
    return 0;
}

void Unit::resolveAttack() {
  type->resolveAttack(*this);
}

void Unit::promote() {
    type->promote(*this);
}

Unit::Unit(const UnitType* type, Player& owner) : hp(type->initialHp), position(0), type(type), owner(owner)  {}
