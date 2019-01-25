//
// Created by bjornir on 09/01/19.
//

#include "Unit.hpp"
#include "UnitType.hpp"

int Unit::getHp() const {
    return hp;
}

const UnitType* Unit::getType() const {
  return type;
}

int Unit::hurt(int damage){
    hp -= damage;
    if(hp <= 0){
        int reward = type->price/2;
        owner.getBf().kill(position);
        return reward;
    }
    return 0;
}

void Unit::resolveAttack() {
    if(canAttack)  canAttack = !type->resolveAttack(*this);
}

void Unit::promote() {
    type->promote(*this);
}

std::string Unit::generateSaveString() {
    std::string save = std::to_string(hp)+"\n"+std::to_string(position)+"\n"+"\n"+type->generateSaveString();
    return save;
}

Unit::Unit(const UnitType* type, Player& owner) : hp(type->initialHp), position(0), type(type), owner(owner)  {}

void Unit::newTurn(){
    canAttack = true;
}

