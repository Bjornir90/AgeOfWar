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
        std::cout<<"Pièces : "<< getMoney() <<"\r\nEntrez le nom de l'unité à acheter (nothing, catapult, soldier ou archer) :"<<std::endl;
        std::cin >> unitName;
        Unit *toBuy;
        if (unitName == "catapult" || unitName == "c") {
           toBuy = new Unit(&Catapult::instance, *this);
        } else if (unitName == "archer" || unitName == "a") {
            toBuy = new Unit(&Archer::instance, *this);
        } else if (unitName == "soldier" || unitName == "s") {
            toBuy = new Unit(&Soldier::instance, *this);
        } else if (unitName == "superunicorn") {
            //Spawn a special unit
        } else if (unitName == "nothing" || unitName == "n"){
            return nullptr;
        } else {
            std::cout << "Ce nom n'est pas valide"<<std::endl;
            continue;
        }
        if(toBuy->type->price <= this->getMoney()){
            this->spendMoney(toBuy->type->price);
            return toBuy;
        }
        std::cout<<"Tu n'as pas assez d'argent pour acheter cette unité"<<std::endl;
    }
}

Human::Human(int money, int hp, BattlefieldAccessor& bf) : Player(money, hp, bf) {}
