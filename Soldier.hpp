//
// Created by bjornir on 09/01/19.
//

#ifndef AGEOFWAR_SOLDIER_HPP
#define AGEOFWAR_SOLDIER_HPP


#include "Unit.hpp"

class Soldier : public Unit{
protected:
    void resolveAttack();
    void resolveMovement();
    void hurt(int damage){
        hp -= damage;
        if(hp<1){

        }
    }

public:
    Soldier(Battlefield& bf) : battlefield(bf) {
        initialhp = 10;
        hp = initialhp;
        attackpower = 4;
        price = 10;
    }
};


#endif //AGEOFWAR_SOLDIER_HPP
