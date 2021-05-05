#ifndef ADVENTURER_HPP
#define ADVENTURER_HPP

#include "Weapon.hpp"
#include <iostream>
#include <string>

class Adventurer
{
protected:
  int m_currHp;
  int m_maxHp;
  int m_currSta;
  int m_maxSta;
  std::string m_name;
  std::string m_race;
  bool m_isDead = false;
  bool m_zeroHp = false;
  Weapon *m_weapon;

public:
  Adventurer(int maxHp, int maxSta, std::string name, std::string race, Weapon *weapon) : m_maxHp(maxHp), m_currHp(maxHp), m_maxSta(maxSta), m_currSta(maxSta), m_name(name), m_race(race), m_weapon(weapon){};
  Adventurer(const Adventurer &adv, Weapon *weapon) : m_maxHp(adv.m_maxHp), m_currHp(adv.m_currHp), m_maxSta(adv.m_maxSta), m_currSta(adv.m_currSta), m_name(adv.m_name), m_race(adv.m_race), m_weapon(weapon){};

  void die();
  void operator+=(int n);            //Get healed
  void operator-=(int n);            //Take damage
  void operator<<(std::string line); //Speak
  virtual void stats();
  virtual int attack();

  //Setters
  void setStamina(int n);
  void setHP(int n);

  //Getters
  std::string getRace();
  Weapon getWeapon();
  std::string getName();

  bool isDead();
  bool hasZeroHp();
};

Adventurer *createHuman(std::string name);
Adventurer *createDwarf(std::string name);
Adventurer *createElf(std::string name);
Adventurer *createGrunt(int n);

#endif // !ADVENTURER_HPP