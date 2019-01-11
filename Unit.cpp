//
// Created by bjornir on 09/01/19.
//

#include "Unit.hpp"

int Unit::getHp() const {
    return hp;
}

int Unit::getInitialhp() const {
    return initialhp;
}

int Unit::getAttackpower() const {
    return attackpower;
}

int Unit::getPrice() const {
    return price;
}

int Unit::hurt(int damage){
    hp -= damage;
    return price/2;
}

int Unit::getPosition() const {
    return position;
}

void Unit::setPosition(int position) {
    Unit::position = position;
}

Unit::Unit(int hp, int initialhp, int attackpower, int price, Player& owner) : hp(hp), initialhp(
        initialhp), attackpower(attackpower), price(price), position(0), owner(owner) {}
