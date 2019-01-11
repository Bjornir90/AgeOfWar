//
// Created by bjornir on 09/01/19.
//

#ifndef AGEOFWAR_PLAYER_HPP
#define AGEOFWAR_PLAYER_HPP


#include "Unit.fwd.hpp"
#include "Battlefield.fwd.hpp"

class Player {
private:
    int money, hp;
protected:
    bool spendMoney(int amount);
    BattlefieldAccessor& bf;
public:
    void addRewardMoney(int reward);

    int getMoney() const;

    virtual Unit * getNextBuy() = 0;

    BattlefieldAccessor& getBf() const;


    Player(int money, int hp, BattlefieldAccessor& bf);
};


#endif //AGEOFWAR_PLAYER_HPP
