//
// Created by bjornir on 09/01/19.
//

#ifndef AGEOFWAR_CATAPULT_HPP
#define AGEOFWAR_CATAPULT_HPP


#include "Unit.hpp"

class Catapult : public Unit{
protected:
    void resolveAttack();
    void resolveMovement();

public:
    Catapult() : Unit(12, 12, 6, 20) {
    }

};


#endif //AGEOFWAR_CATAPULT_HPP
