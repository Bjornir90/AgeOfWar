#include "Battlefield.hpp"
#include <exception>

Battlefield::Battlefield() : leftAccess(field), rightAccess(field) {
  for(unsigned int i = 0; i < FIELD_SIZE; i++) field[i] = NULL;
}

BattlefieldAccessor::BattlefieldAccessor(Unit** field) : field(field) {}

Unit*& BattlefieldLeftAccessor::operator [] (int idx) {
  if(idx < 0 || idx > FIELD_SIZE) throw std::out_of_range("The given index exceeds the range of the field.");
  return field[idx];
}

Unit*& BattlefieldRightAccessor::operator [] (int idx) {
  if(idx < 0 || idx > FIELD_SIZE) throw std::out_of_range("The given index exceeds the range of the field.");
  return field[FIELD_SIZE - idx];
}

bool BattlefieldAccessor::moveFwd (int idx) {
  if(idx < 0 || idx > FIELD_SIZE - 2) throw std::out_of_range("The given index exceeds the range of field, or unit will exceed allowed position if moved.");
  if((*this)[idx+1] != NULL) return false;
  (*this)[idx+1] = (*this)[idx];
  (*this)[idx] = NULL;
  return true;
}

