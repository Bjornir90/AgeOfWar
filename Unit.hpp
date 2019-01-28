
//
// Created by bjornir on 09/01/19.
//

#ifndef AGEOFWAR_UNIT_HPP
#define AGEOFWAR_UNIT_HPP

#include <string>
#include <fstream>
#include "Hurtable.hpp"
#include "Battlefield.hpp"
#include "UnitType.hpp"
#include "Player.hpp"

class Unit : public Hurtable {
private:

    bool canAttack;
protected:

    bool canMove;

public:
    int position;
    const UnitType* type;
    Player& owner;

    int hurt(int damage);
    inline const UnitType* getType() const;
    void resolveAttack();
    void promote();
    Unit(const UnitType* type, Player& owner);
    inline std::string name() const {
        return type->name();
    }
    inline std::string printableHP(){
        return std::to_string(hp)+"PV";
    }

    std::string generateSaveString();

    static Unit *loadFromStream(std::ifstream &saveFile, Player *player0, Player *player1);

    void newTurn();

    bool isCapableOfMoving() const;

    //Give the catapult access to the canMove attribute
    friend class Catapult;

};


#endif //AGEOFWAR_UNIT_HPP
