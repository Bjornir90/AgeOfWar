
//
// Created by bjornir on 09/01/19.
//

#ifndef AGEOFWAR_UNIT_HPP
#define AGEOFWAR_UNIT_HPP


class Unit {
protected:
    int hp, initialhp, attackpower, price, team;
    Battlefield& battlefield;
    virtual void resolveAttack() = 0;
    virtual void resolveMovement() = 0;
    virtual void hurt(int damage) = 0;
public:
    int getHp() const;

    int getInitialhp() const;

    int getAttackpower() const;

    int getPrice() const;

    int getTeam() const;
};


#endif //AGEOFWAR_UNIT_HPP
