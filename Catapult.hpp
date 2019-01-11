//
// Created by bjornir on 09/01/19.
//

#ifndef AGEOFWAR_CATAPULT_HPP
#define AGEOFWAR_CATAPULT_HPP


#include "Unit.hpp"

class Catapult : public Unit{
protected:
    void resolveAttack();

public:
    Catapult(Player& owner) : Unit(12, 12, 6, 20, owner) {
    }

};


#endif //AGEOFWAR_CATAPULT_HPP
