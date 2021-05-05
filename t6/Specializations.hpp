#ifndef SPECIALIZATIONS_HPP
#define SPECIALIZATIONS_HPP

#include "Adventurer.hpp"
#include <iostream>
#include <cstdlib>
#include <string>

class Wizard : public Adventurer
{
private:
  int m_maxMana;
  int m_currMana;

public:
  Wizard(int maxHp, int maxSta, int maxMana, std::string name, std::string race, Weapon *weapon) : m_maxMana(maxMana), m_currMana(maxMana), Adventurer(maxHp, maxSta, name, race, weapon){};
  Wizard(int maxMana, const Adventurer &adv, Weapon *weapon) : m_maxMana(maxMana), m_currMana(maxMana), Adventurer(adv, weapon){};

  void stats();
  int attack();
};

Wizard *createWizard(Adventurer &adv);

class Ranger : public Adventurer
{
private:
  int m_maxAmmo;
  int m_currAmmo;

public:
  Ranger(int maxHp, int maxSta, int maxAmmo, std::string name, std::string race, Weapon *weapon) : m_maxAmmo(maxAmmo), m_currAmmo(maxAmmo), Adventurer(maxHp, maxSta, name, race, weapon){};
  Ranger(int maxAmmo, const Adventurer &adv, Weapon *weapon) : m_maxAmmo(maxAmmo), m_currAmmo(maxAmmo), Adventurer(adv, weapon){};

  void stats();
  int attack();
};

Ranger *createRanger(Adventurer &adv);

class Fighter : public Adventurer
{
private:
  int m_maxDmgDie;
  int m_currDmgDie;

public:
  Fighter(int maxHp, int maxSta, int maxDmgDie, std::string name, std::string race, Weapon *weapon) : m_maxDmgDie(maxDmgDie), m_currDmgDie(maxDmgDie), Adventurer(maxHp, maxSta, name, race, weapon){};
  Fighter(int maxDmgDie, const Adventurer &adv, Weapon *weapon) : m_maxDmgDie(maxDmgDie), m_currDmgDie(maxDmgDie), Adventurer(adv, weapon){};

  void stats();
  int attack();
};

Fighter *createFighter(Adventurer &adv);

#endif // !ESPECIALIZATIONS_HPP