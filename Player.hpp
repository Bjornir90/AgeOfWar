//
// Created by bjornir on 09/01/19.
//

#ifndef AGEOFWAR_PLAYER_HPP
#define AGEOFWAR_PLAYER_HPP


#include "Unit.hpp"

class Player {
private:
    int money, team, hp;
    static Player players [];

public:
    static void addRewardMoney(const Unit &killed);
    static Player& getInstance(int team);

    Player(int money, int team, int hp);
};


#endif //AGEOFWAR_PLAYER_HPP
