#pragma once
#include "Battlefield.fwd.hpp"
#include "Unit.fwd.hpp"
#include "Player.fwd.hpp" // no need for more..
#include <iostream>
#include <functional>
#include <utility>

class BattlefieldAccessor {
protected:
  Unit** const field;
  BattlefieldAccessor(Unit** field);
public:
  virtual Unit*& operator [] (int idx) const = 0;
  bool moveFwd(int idx) const;
  void kill(int idx) const;
};

class BattlefieldLeftAccessor : public BattlefieldAccessor {
public:
  BattlefieldLeftAccessor(Unit** f) : BattlefieldAccessor(f) {}
  Unit*& operator [] (int idx) const;
};

class BattlefieldRightAccessor : public BattlefieldAccessor {
public:
  BattlefieldRightAccessor(Unit** f) : BattlefieldAccessor(f) {}
  Unit*& operator [] (int idx) const;
};



class Battlefield {
private:
  Unit* field[BF_SIZE];
  Player* p0, *p1;
  void _printPlayerColor(std::ostream& strm, Player* p) const;
  void _printLoop(std::ostream& strm, const BattlefieldAccessor& bf, std::function<void(Unit*u)>) const;
public:
  Battlefield();
  BattlefieldLeftAccessor leftAccess;
  BattlefieldRightAccessor rightAccess;
  void setPlayers(Player* p0, Player* p1);
  void print(std::ostream& strm, const BattlefieldAccessor& bf) const;
  void print(std::ostream& strm) const;
};
