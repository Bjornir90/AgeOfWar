#pragma once
#include "Unit.fwd.hpp"
#include "common.hpp"


class BattlefieldAccessor {
protected:
  Unit** field;
  BattlefieldAccessor(Unit** field);
public:
  virtual Unit*& operator [] (int idx) = 0;
  bool moveFwd(int idx);
  void kill(int idx);
};

class BattlefieldLeftAccessor : public BattlefieldAccessor {
public:
  BattlefieldLeftAccessor(Unit** f) : BattlefieldAccessor(f) {}
  Unit*& operator [] (int idx);
};

class BattlefieldRightAccessor : public BattlefieldAccessor {
public:
  BattlefieldRightAccessor(Unit** f) : BattlefieldAccessor(f) {}
  Unit*& operator [] (int idx);
};



class Battlefield {
private:
  Unit* field[FIELD_SIZE + 1];
public:
  Battlefield();
  BattlefieldLeftAccessor leftAccess;
  BattlefieldRightAccessor rightAccess;
};
