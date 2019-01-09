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

int Unit::getTeam() const {
    return team;
}

Unit::Unit(int hp, int initialhp, int attackpower, int price, int team, Battlefield &battlefield) : hp(hp), initialhp(
        initialhp), attackpower(attackpower), price(price), team(team), battlefield(battlefield) {}

