//
// Created by bjornir on 09/01/19.
//

#include "Unit.hpp"
#include "Player.hpp"

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

void Unit::hurt(int damage){
    hp -= damage;
    if(hp<1){
        Player::addRewardMoney(*((Unit*)this));
    }
}

Unit::Unit(int hp, int initialhp, int attackpower, int price, int team, Battlefield &battlefield) : hp(hp), initialhp(
        initialhp), attackpower(attackpower), price(price), team(team), battlefield(battlefield) {}

