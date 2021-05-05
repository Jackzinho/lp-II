#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <cstdlib>
#include <string>

class Weapon
{
private:
  std::string m_name;
  bool m_areaAttack;
  bool m_longRange;
  bool m_magicAttack;
  int m_dmgDie;

public:
  Weapon(std::string name, bool areaAttack, bool longRange, bool magicAttack, int dmgDie) : m_name(name), m_areaAttack(areaAttack), m_longRange(longRange), m_magicAttack(magicAttack), m_dmgDie(dmgDie){};

  // Getters
  bool getAreaAttack();
  bool getLongRange();
  bool getMagicAttack();

  int attack();
};

Weapon* createSword();
Weapon* createStaff();
Weapon* createBow();
Weapon* createClub();

#endif // !WEAPON_HPP