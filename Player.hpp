//
// Created by bjornir on 09/01/19.
//

#ifndef AGEOFWAR_PLAYER_HPP
#define AGEOFWAR_PLAYER_HPP


#include "Unit.fwd.hpp"
#include "Battlefield.hpp"
#include "Base.hpp"

class Player {
private:
    int money, side;//0 for left, 1 for right
protected:
    bool spendMoney(int amount);

    BattlefieldAccessor& bf;
public:
    Base base;

    void addRewardMoney(int reward);

    int getMoney() const;

    //return the unit chosen by the player, with the prompt and input handled inside the function, or the unit the AI will buy.
    virtual Unit * getNextBuy() = 0;

    virtual bool isAI() = 0;

    BattlefieldAccessor& getBf() const;

    Player(int money, int hp, int side, BattlefieldAccessor& bf);

    int getSide() const;

    bool operator==(const Player &other) const;

    bool operator!=(const Player &rhs) const;
};


#endif //AGEOFWAR_PLAYER_HPP
