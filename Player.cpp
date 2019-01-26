//
// Created by bjornir on 09/01/19.
//

#include "Player.hpp"


void Player::addRewardMoney(int reward) {
    this->money += reward;
}

Player::Player(int money, int hp, BattlefieldAccessor& bf) : money(money), bf(bf), base(hp) {}

int Player::getMoney() const {
    return money;
}

bool Player::spendMoney(int amount) {
    if(amount > money) return false;
    money -= amount;
    return true;
}

BattlefieldAccessor& Player::getBf() const {
        return bf;
}

bool Player::operator==(const Player &other) const {
    return (bf == other.getBf());
}

bool Player::operator!=(const Player &rhs) const {
    return !(rhs == *this);
}
