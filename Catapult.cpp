//
// Created by bjornir on 09/01/19.
//

#include "Catapult.hpp"
#include "Battlefield.hpp"

const Catapult Catapult::instance = Catapult();

void Catapult::resolveAttack() {

}

void Catapult::resolveAttack(Unit &u) const {

}

void Catapult::promote(Unit &u) const {
    return;
}

std::string Catapult::name() const {
    return "Catapult";
}

std::string Catapult::generateSaveString() const{
    std::string save = "catapult";
    return save;
}

