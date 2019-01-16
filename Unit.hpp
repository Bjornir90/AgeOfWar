
//
// Created by bjornir on 09/01/19.
//

#ifndef AGEOFWAR_UNIT_HPP
#define AGEOFWAR_UNIT_HPP

#include <string>
#include "Battlefield.hpp"
#include "UnitType.hpp"
#include "Player.hpp"

class Unit {
private:
    int hp;

public:
    int position;
    const UnitType* type;
    Player& owner;

    int hurt(int damage);
    int getHp() const;
    inline void resolveAttack();
    inline void promote();
    Unit(const UnitType* type, Player& owner);
    virtual ~Unit () = default;
    inline std::string name() const {
        return type->name();
    }
    inline std::string printableHP(){
        return "PV : "<<hp;
    }

    std::string generateSaveString();

};


#endif //AGEOFWAR_UNIT_HPP
