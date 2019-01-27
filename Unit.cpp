//
// Created by bjornir on 09/01/19.
//

#include "Unit.hpp"
#include "UnitType.hpp"
#include "Catapult.hpp"
#include "Archer.hpp"
#include "Soldier.hpp"
#include "SuperSoldier.hpp"


const UnitType* Unit::getType() const {
  return type;
}

int Unit::hurt(int damage){
    if(Hurtable::hurt(damage)) {
        int reward = type->price/2;
        owner.getBf().kill(position);
        return reward;
    }
    return 0;
}

void Unit::resolveAttack() {
    if(canAttack)  canAttack = !type->resolveAttack(*this);
}

void Unit::promote() {
    type->promote(*this);
}

std::string Unit::generateSaveString() {
    int side = owner.getSide();
    std::string save = std::to_string(hp)+"\n"+std::to_string(position)+"\n"+type->generateSaveString()+"\n"+std::to_string(side)+"\n";//format is hp; position; typename; side, with newline in place of ;
    return save;
}

Unit::Unit(const UnitType* type, Player& owner) : Hurtable(type->initialHp), position(0), type(type), owner(owner)  {}

void Unit::newTurn(){
    canAttack = true;
}

Unit * Unit::loadFromStream(std::ifstream &saveFile, Player *player0, Player *player1) {
    std::string input;
    int savedPosition, savedHp, filePosition = 0;
    const UnitType *savedType;
    Player *savedOwner;
    while(std::getline(saveFile, input)){
        switch (filePosition){
            case 0:
                filePosition++;
                savedHp = std::stoi(input);
                break;
            case 1:
                filePosition++;
                savedPosition = std::stoi(input);
                break;
            case 2:
                filePosition++;
                if(input == "catapult"){
                    savedType = &Catapult::instance;
                } else if (input == "archer") {
                    savedType = &Archer::instance;
                } else if (input == "soldier"){
                    savedType = &Soldier::instance;
                } else if (input == "supersoldier"){
                    savedType = &SuperSoldier::instance;
                } else {
                    std::cout << "Error, save file invalid" << std::endl;
                    return nullptr;
                }
                break;
            case 3:
                int savedSide = std::stoi(input);
                if(savedSide == 0){
                    savedOwner = player0;
                } else {
                    savedOwner = player1;
                }
                Unit * loadedUnit = new Unit(savedType, *savedOwner);
                loadedUnit->hp = savedHp;
                loadedUnit->position = savedPosition;
                savedOwner->getBf()[savedPosition] = loadedUnit;
                return loadedUnit;
        }
    }
}