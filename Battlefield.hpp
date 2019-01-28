#pragma once
#include "Battlefield.fwd.hpp"
#include "Unit.fwd.hpp"
#include "Player.fwd.hpp"
#include "Base.hpp"
#include "Color.hpp"
#include <iostream>
#include <functional>
#include <utility>

#define P0_COLOR Color::GREEN // display color of player0
#define P1_COLOR Color::BRIGHT_RED // and of player1

/*Class that allows access to the battlefield, is abstract because you can only get one of the child : left or right,
which determine at which end of the battlefield the origin is */
class BattlefieldAccessor {
protected:
  Unit** const field;
  Base* oppositeBase;
  BattlefieldAccessor(Unit** field);
  friend class Battlefield;
public:
  virtual Unit*& operator [] (int idx) const = 0;
  virtual Hurtable* getEnnemy(int idx) const;
  bool moveFwd(int idx) const;
  void kill(int idx) const;
  bool operator==(const BattlefieldAccessor& rhs) const;
  bool operator!=(const BattlefieldAccessor& rhs) const;
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
  Player *p0, *p1;
  const Color _getUnitColor(Unit* u) const;
  void _printLoop(std::ostream& strm, const BattlefieldAccessor& bf, std::function<void(Unit*u)>) const;
public:
  Battlefield();
  BattlefieldLeftAccessor leftAccess;
  BattlefieldRightAccessor rightAccess;
  void setPlayers(Player* p0, Player* p1);
  void print(std::ostream& strm, const BattlefieldAccessor& bf) const;
  void print(std::ostream& strm) const;
};
