//
// Created by bjornir on 11/01/19.
//

#include <string>
#include <iostream>
#include "Human.hpp"
#include "Catapult.hpp"
#include "Archer.hpp"
#include "Soldier.hpp"

Unit * Human::getNextBuy() {
    std::string unitName;
    while(true) {
        std::cout<<"Pièces : "<< getMoney() <<"\r\nEntrez le nom de l'unité à acheter (rien, catapulte, soldat ou archer) :"<<std::endl;
        std::cin >> unitName;
        UnitType const* toBuy;
        if (unitName == "catapulte" || unitName == "c") {
          toBuy = &Catapult::instance;
        } else if (unitName == "archer" || unitName == "a") {
          toBuy = &Archer::instance;
        } else if (unitName == "soldat" || unitName == "s") {
          toBuy = &Soldier::instance;
        } else if (unitName == "rien" || unitName == "r"){
          return nullptr;
        } else {
            std::cout << "Ce nom n'est pas valide"<<std::endl;
            continue;
        }
        if(toBuy->price <= this->getMoney()){
            this->spendMoney(toBuy->price);
            return new Unit(toBuy, *this);
        }
        std::cout<<"Tu n'as pas assez d'argent pour acheter cette unité"<<std::endl;
    }
}

Human::Human(int money, int hp, int side, BattlefieldAccessor& bf) : Player(money, hp, side, bf) {}

bool Human::isAI() {
    return false;
}
