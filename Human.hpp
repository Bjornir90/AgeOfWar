//
// Created by bjornir on 11/01/19.
//

#ifndef AGEOFWAR_HUMAN_HPP
#define AGEOFWAR_HUMAN_HPP


#include "Player.hpp"

class Human : public Player{
public:
    Unit * getNextBuy() override;

    Human(int money, int hp, int side, BattlefieldAccessor& bf);
};


#endif //AGEOFWAR_HUMAN_HPP
