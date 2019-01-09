//
// Created by bjornir on 09/01/19.
//

#ifndef AGEOFWAR_PLAYER_HPP
#define AGEOFWAR_PLAYER_HPP


#include "Unit.hpp"

class Player {
private:
    int money, team;
    static Player players [];

public:
    static void addRewardMoney(Unit& killed);
    static Player& getInstance(int team);

};


#endif //AGEOFWAR_PLAYER_HPP
