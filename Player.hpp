//
// Created by bjornir on 09/01/19.
//

#ifndef AGEOFWAR_PLAYER_HPP
#define AGEOFWAR_PLAYER_HPP


#include "Unit.hpp"

class Player {
private:
    int money, team, hp;
    static Player players [2];

public:
    static void addRewardMoney(const Unit &killed);
    static Player& getInstance(int team);

    int getMoney() const;

    Player(int money, int team, int hp);
    static void addPlayer(Player toAdd, int index){
        players[index] =
    }
};


#endif //AGEOFWAR_PLAYER_HPP
