//
// Created by bjornir on 09/01/19.
//

#ifndef AGEOFWAR_CATAPULT_HPP
#define AGEOFWAR_CATAPULT_HPP


#include "UnitType.hpp"
#include "Battlefield.hpp"

class Catapult : public UnitType{
protected:
    void resolveAttack();

public:
    Catapult() : UnitType(12, 20, 6) {
    }

    static const Catapult instance;

    bool resolveAttack(Unit &u) const override;

    void promote(Unit &u) const override;

    std::string name() const override;

    std::string generateSaveString() const override;
};


#endif //AGEOFWAR_CATAPULT_HPP
