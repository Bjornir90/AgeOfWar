//
// Created by bjornir on 09/01/19.
//

#include <cstdlib>
#include "Player.hpp"

void Player::addRewardMoney(Unit &killed) {
    int playerTeam = abs(killed.getTeam()-1);
    Player& playerThatGotReward = Player::getInstance(playerTeam);
    playerThatGotReward.money += killed.getPrice()/2;
}

Player& Player::getInstance(int team) {
    return players[team];
}