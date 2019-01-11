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
            Catapult *catapult = new Catapult();
            if(spendMoney(catapult->getPrice())) return catapult;
        } else if (unitName == "archer") {
            Archer *archer = new Archer();
            if(spendMoney(archer->getPrice())) return archer;
        } else if (unitName == "soldier") {
            Soldier *soldier = new Soldier();
            if(spendMoney(soldier->getPrice())) return soldier;
        } else if (unitName == "superunicorn") {
            //Spawn a special unit
        } else if (unitName == "nothing"){
            return nullptr;
        }
        std::cout<<"HÉ T'ES PAUVRE !"<<std::endl;
    }
}

Human::Human(int money, int team, int hp) : Player(money, team, hp) {}

