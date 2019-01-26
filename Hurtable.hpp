#pragma once

class Hurtable {
protected:
  int hp;
public:
  Hurtable(int hp);
  virtual int hurt(int damage);
  int getHp() const;
  virtual ~Hurtable() = default;
};
