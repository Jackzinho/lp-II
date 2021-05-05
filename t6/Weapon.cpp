#include "Weapon.hpp"

bool Weapon::getAreaAttack()
{
  return m_areaAttack;
}

bool Weapon::getLongRange()
{
  return m_longRange;
}

bool Weapon::getMagicAttack()
{
  return m_magicAttack;
}

int Weapon::attack()
{
  return rand() % m_dmgDie + 1;
}

Weapon* createSword()
{
  return new Weapon("Sword", false, false, false, 10);
}

Weapon* createBow()
{
  return new Weapon("Bow", false, true, false, 6);
}

Weapon* createStaff()
{
  return new Weapon("Staff", true, true, true, 4);
}

Weapon* createClub()
{
  return new Weapon("Sword", false, false, false, 4);
}