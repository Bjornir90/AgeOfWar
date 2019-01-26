#include "Hurtable.hpp"


Hurtable::Hurtable(int hp) : hp(hp) {}

int Hurtable::hurt(int damage) {
  hp -= damage;
  if(hp <= 0) return 1;
  return 0;
}


int Hurtable::getHp() const {
  return hp;
}
