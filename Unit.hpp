
//
// Created by bjornir on 09/01/19.
//

#ifndef AGEOFWAR_UNIT_HPP
#define AGEOFWAR_UNIT_HPP


class Unit {
protected:
    int hp, initialhp, attackpower, price;
    Battlefield * battlefield;
    virtual void resolveAttack() = 0;
    virtual void resolveMovement() = 0;
    virtual void hurt(int damage) = 0;

};


#endif //AGEOFWAR_UNIT_HPP
