#include "UnitType.hpp"
#include "Unit.hpp"

UnitType::UnitType(int price, int initialHp, int attackDamage) : price(price), initialHp(initialHp), attackDamage(attackDamage) {}

void UnitType::printAttackMove(std::string attackerName, Hurtable *defender) const {
    std::cout << attackerName<<" attack and reduces the ennemy to "<<((defender->getHp() < 0)?0:defender->getHp())<<" hp"<<std::endl;
}
