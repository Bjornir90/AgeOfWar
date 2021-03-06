//
// Created by bjornir on 09/01/19.
//

#ifndef AGEOFWAR_ARTIFICIALINTELLIGENCE_HPP
#define AGEOFWAR_ARTIFICIALINTELLIGENCE_HPP


#include "Player.hpp"

class ArtificialIntelligence : public Player {
public:
    Unit * getNextBuy();

    bool isAI() override;

    ArtificialIntelligence(int money, int hp, int side, BattlefieldAccessor& bf);
};


#endif //AGEOFWAR_ARTIFICIALINTELLIGENCE_HPP
