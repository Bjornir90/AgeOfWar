//
// Created by bjornir on 09/01/19.
//

#include <cstdlib>
#include "Player.hpp"


void Player::addRewardMoney(const Unit &killed) {
    int playerTeam = abs(killed.getTeam()-1);
    Player& playerThatGotReward = Player::getInstance(playerTeam);
    playerThatGotReward.money += killed.getPrice()/2;
}

Player& Player::getInstance(int team) {
    return players[team];
}

Player::Player(int money, int team, int hp) : money(money), team(team), hp(hp) {}

int Player::getMoney() const {
    return money;
}
