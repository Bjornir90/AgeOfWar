//
// Created by bjornir on 09/01/19.
//

#include <cstdlib>
#include "Player.hpp"


void Player::addRewardMoney(const Unit &killed) {
    this->money += killed.getPrice()/2;
}

Player::Player(int money, int team, int hp) : money(money), team(team), hp(hp) {}

int Player::getMoney() const {
    return money;
}

bool Player::spendMoney(int amount) {
    if(amount > money) return false;
    money -= amount;
    return true;
}
