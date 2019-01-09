//
// Created by bjornir on 09/01/19.
//

#ifndef AGEOFWAR_SOLDIER_HPP
#define AGEOFWAR_SOLDIER_HPP


#include "Unit.hpp"
#include "Battlefield.hpp"

class Soldier : public Unit{
protected:
    void resolveAttack();
    void resolveMovement();

public:
    Soldier(Battlefield& bf, int team) : Unit(10, 10, 4, 10, team, Battlefield& bf) {
    }
};


#endif //AGEOFWAR_SOLDIER_HPP
