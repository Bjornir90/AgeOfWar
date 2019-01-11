//
// Created by bjornir on 09/01/19.
//

#include <cstdlib>
#include "Player.hpp"


void Player::addRewardMoney(int reward) {
    this->money += reward;
}

Player::Player(int money, int team, int hp, BattlefieldAccessor * bf) : money(money), team(team), hp(hp), bf(bf) {}

int Player::getMoney() const {
    return money;
}

bool Player::spendMoney(int amount) {
    if(amount > money) return false;
    money -= amount;
    return true;
}

BattlefieldAccessor *Player::getBf() const {
    return bf;
}
