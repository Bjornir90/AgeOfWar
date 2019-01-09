//
// Created by bjornir on 09/01/19.
//

#ifndef AGEOFWAR_ARCHER_HPP
#define AGEOFWAR_ARCHER_HPP


#include "Unit.hpp"

class Archer : public Unit{
protected:
    void resolveAttack();
    void resolveMovement();

public:
    Archer(Battlefield& bf, int team) : Unit(8, 8, 3, 12, team, Battlefield& bf) {
    }
};


#endif //AGEOFWAR_ARCHER_HPP
