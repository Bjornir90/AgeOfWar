#include "Battlefield.hpp"
#include <stdexcept>
#include "Unit.hpp"
#include <iomanip>
#include "Player.hpp"

#define BF_DISP_WIDTH 12 // display width (in chars) of one cell for print()
#define BF_COLORS 1 // enable or disable color display

#define BF_P0_COLOR "\033[32m" // customize colors for player0
#define BF_P1_COLOR "\033[33m" // player1
#define BF_DEF_COLOR "\033[0m" // initial color


Battlefield::Battlefield() : leftAccess(field), rightAccess(field) {
  for(unsigned int i = 0; i < BF_SIZE; i++) field[i] = NULL;
}

void Battlefield::setPlayers(Player* p0, Player* p1) {
  this->p0 = p0;
  this->p1 = p1;
  leftAccess.oppositeBase = &(p1->base);
  rightAccess.oppositeBase = &(p0->base);
}

void Battlefield::_printLoop(std::ostream& strm, const BattlefieldAccessor& bf,
                        std::function<void(Unit*u)> func) const {
  strm << '|';
  for(unsigned int i = 0; i < BF_SIZE; i++) {
    if(bf[i]) {
      #if BF_COLORS==1
        _printPlayerColor(strm, &(bf[i]->owner));
      #endif

      strm << std::setfill(' ') << std::left << std::setw(BF_DISP_WIDTH);
      func(bf[i]);

      #if BF_COLORS==1
        strm << BF_DEF_COLOR;
      #endif
    }
    else for(unsigned short i=0; i<BF_DISP_WIDTH; i++) strm << ' ';

    strm << '|';
  }
  strm << std::endl;
}


void Battlefield::print(std::ostream& strm, const BattlefieldAccessor& bf) const {

  std::cout << "Player 1: " << p0->base.getHp() << std::endl;
  std::cout << "Player 2: " << p1->base.getHp() << std::endl;
  _printLoop(strm, bf, [&](Unit* u)->void{
    if(&(u->owner) == p0) strm << "P1";
    else if(&(u->owner) == p1) strm << "P2";
  });
  _printLoop(strm, bf, [&](Unit* u)->void{strm << u->name();});
  _printLoop(strm, bf, [&](Unit* u)->void{strm << u->printableHP();});

}

void Battlefield::print(std::ostream& strm) const {
  print(strm, leftAccess);
}

void Battlefield::_printPlayerColor(std::ostream& strm, Player* p) const {
  if(p == p0) strm << BF_P0_COLOR;
  else if(p == p1) strm << BF_P1_COLOR;
}

BattlefieldAccessor::BattlefieldAccessor(Unit** field) : field(field) {}

Hurtable* BattlefieldAccessor::getEnnemy(int idx) const {
  Unit* u = (*this)[idx];

  if(u == nullptr) {
    if(idx == BF_SIZE-1) return oppositeBase;
    return nullptr;
  }

  if(u->owner.getBf() != *this)
    return u;

  return nullptr;
}

Unit*& BattlefieldLeftAccessor::operator [] (int idx) const {
  if(idx < 0 || idx >= BF_SIZE) throw std::out_of_range("The given index exceeds the range of the field.");
  return field[idx];
}

Unit*& BattlefieldRightAccessor::operator [] (int idx) const {
  if(idx < 0 || idx >= BF_SIZE) throw std::out_of_range("The given index exceeds the range of the field.");
  return field[BF_SIZE-1 - idx];
}

bool BattlefieldAccessor::moveFwd (int idx) const {
  if(idx < 0 || idx >= BF_SIZE - 2) return false;
  if((*this)[idx+1] != NULL) return false;
  (*this)[idx+1] = (*this)[idx];
  (*this)[idx] = NULL;
  return true;
}

void BattlefieldAccessor::kill (int idx) const {
  Unit*& u = (*this)[idx];
  if(u == NULL) return;
  delete u;
  u = NULL;
}

bool BattlefieldAccessor::operator==(const BattlefieldAccessor &rhs) const {
  return this == &rhs;
}

bool BattlefieldAccessor::operator!=(const BattlefieldAccessor &rhs) const {
  return !(*this == rhs);
}
