#include "UnitType.hpp"
#include "Unit.hpp"

UnitType::UnitType(int price, int initialHp, int attackDamage) : price(price), initialHp(initialHp), attackDamage(attackDamage) {}

void UnitType::printAttackMove(std::string attackerName, Hurtable *defender) const {
    std::cout << attackerName<<" attaque et réduit l'ennemi à "<<((defender->getHp() < 0)?0:defender->getHp())<<" pv"<<std::endl;
}
