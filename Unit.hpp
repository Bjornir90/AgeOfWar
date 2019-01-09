
//
// Created by bjornir on 09/01/19.
//

#ifndef AGEOFWAR_UNIT_HPP
#define AGEOFWAR_UNIT_HPP
#include "Battlefield.hpp"



class Unit {
protected:
    int hp, initialhp, attackpower, price, team;
    Battlefield& battlefield;
    virtual void resolveAttack() = 0;
    virtual void resolveMovement() = 0;
    void hurt(int damage);
public:
    int getHp() const;

    int getInitialhp() const;

    int getAttackpower() const;

    int getPrice() const;

    int getTeam() const;

    Unit(int hp, int initialhp, int attackpower, int price, int team, Battlefield &battlefield);
};


#endif //AGEOFWAR_UNIT_HPP
