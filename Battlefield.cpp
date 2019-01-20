#include "Battlefield.hpp"
#include <stdexcept>
#include "Unit.hpp"
#include <iomanip>

#define BF_DISP_WIDTH 12 // display width (in chars) of one cell for print()
#define BF_COLORS 1 // enable or disable color display

#define BF_P0_COLOR "\033[32m" // customize colors for player0
#define BF_P1_COLOR "\033[34m" // player1
#define BF_DEF_COLOR "\033[39m" // initial color


Battlefield::Battlefield() : leftAccess(field), rightAccess(field) {
  for(unsigned int i = 0; i < BF_SIZE; i++) field[i] = NULL;
}

void Battlefield::setPlayers(Player* p0, Player* p1) {
  this->p0 = p0;
  this->p1 = p1;
}

void Battlefield::_printLoop(std::ostream& strm, const BattlefieldAccessor& bf,
                        std::function<void(Unit*u)> func) const {
                        // void(*func)(std::ostream&, Unit*)) const {
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

Unit*& BattlefieldLeftAccessor::operator [] (int idx) const {
  if(idx < 0 || idx >= BF_SIZE) throw std::out_of_range("The given index exceeds the range of the field.");
  return field[idx];
}

Unit*& BattlefieldRightAccessor::operator [] (int idx) const {
  if(idx < 0 || idx >= BF_SIZE) throw std::out_of_range("The given index exceeds the range of the field.");
  return field[BF_SIZE-1 - idx];
}

bool BattlefieldAccessor::moveFwd (int idx) const {
  if(idx < 0 || idx >= BF_SIZE - 2) throw std::out_of_range("The given index exceeds the range of field, or unit will exceed allowed position if moved.");
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
