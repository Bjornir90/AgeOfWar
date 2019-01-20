#pragma once

#include <string>
#include "UnitType.fwd.hpp"
#include "Unit.hpp"
#include "Battlefield.fwd.hpp"

class Archer : public UnitType {
public:
    Archer() : UnitType(12, 8, 3){};
    static const Archer instance;

    void promote(Unit &u) const override;

    void resolveAttack(Unit &u) const;

    inline std::string name() const override;

    std::string generateSaveString() const override;
};
