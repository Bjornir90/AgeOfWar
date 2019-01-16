//
// Created by bjornir on 09/01/19.
//

#ifndef AGEOFWAR_SOLDIER_HPP
#define AGEOFWAR_SOLDIER_HPP


#include "UnitType.hpp"

class Soldier : public UnitType{
public:
    Soldier() : UnitType(10, 10, 4) {
    }

    static const Soldier instance;

    void resolveAttack(Unit &u) const override;

    void promote(Unit &u) const override;

    std::string name() override;

    std::string generateSaveString() const override;
};


#endif //AGEOFWAR_SOLDIER_HPP
