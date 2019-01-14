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
        std::cout<<"Entrez le nom de l'unité à acheter (nothing, catapult, soldier ou archer) :"<<std::endl;
        std::cin >> unitName;
        if (unitName == "catapult") {
            Catapult *catapult = new Catapult(*this);
            if(spendMoney(catapult->getPrice())) return catapult;
            delete catapult;
        } else if (unitName == "archer") {
            Archer *archer = new Archer(*this);
            if(spendMoney(archer->getPrice())) return archer;
            delete archer;
        } else if (unitName == "soldier") {
            Soldier *soldier = new Soldier(*this);
            if(spendMoney(soldier->getPrice())) return soldier;
            delete soldier;
        } else if (unitName == "superunicorn") {
            //Spawn a special unit
        } else if (unitName == "nothing"){
            return nullptr;
        }
        std::cout<<"HÉ T'ES PAUVRE !"<<std::endl;
    }
}

Human::Human(int money, int hp, BattlefieldAccessor& bf) : Player(money, hp, bf) {}
