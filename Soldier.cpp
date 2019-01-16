//
// Created by bjornir on 09/01/19.
//

#include "Soldier.hpp"
#include "SuperSoldier.hpp"
#include "Player.hpp"

const Soldier Soldier::instance = Soldier();

void Soldier::resolveAttack(Unit &u) const {

}

void Soldier::promote(Unit &u) const {
    u.type = &SuperSoldier::instance;
}

std::string Soldier::name() {
    return "Soldier";
}

std::string Soldier::generateSaveString() const {
    std::string save = "soldier";
    return save;
}
