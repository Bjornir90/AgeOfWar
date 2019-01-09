//
// Created by bjornir on 09/01/19.
//

#include "Soldier.hpp"
#include "Player.hpp"

void Soldier::hurt(int damage){
    hp -= damage;
    if(hp<1){
        Player::addRewardMoney(*((Unit*)this));
        battlefield
    }

}