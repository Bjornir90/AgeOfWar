
//
// Created by bjornir on 09/01/19.
//

#ifndef AGEOFWAR_UNIT_HPP
#define AGEOFWAR_UNIT_HPP

#include "Battlefield.hpp"
#include "UnitType.fwd.hpp"
#include "Player.hpp"

class Unit {
private:
    int hp;

public:
    int position;
    const UnitType& type;
    Player& owner;

    int hurt(int damage);
    int getHp() const;
    inline void resolveAttack();
    Unit(const UnitType& type, Player& owner);
    virtual ~Unit () = default;

};


#endif //AGEOFWAR_UNIT_HPP
