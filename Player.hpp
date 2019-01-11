//
// Created by bjornir on 09/01/19.
//

#ifndef AGEOFWAR_PLAYER_HPP
#define AGEOFWAR_PLAYER_HPP


#include "Unit.hpp"

class Player {
private:
    int money, team, hp;
protected:
    bool spendMoney(int amount);
    BattlefieldAccessor * bf;
public:
    void addRewardMoney(const Unit &killed);

    int getMoney() const;

    virtual Unit * getNextBuy() = 0;




    Player(int money, int team, int hp, BattlefieldAccessor * bf);
};


#endif //AGEOFWAR_PLAYER_HPP
