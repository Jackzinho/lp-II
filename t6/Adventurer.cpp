#include "Adventurer.hpp"

void Adventurer::die()
{
  std::cout << m_name << " has likely died of unnatural causes." << std::endl;
  m_isDead = true;
};

void Adventurer::operator+=(int n)
{
  std::cout << m_name << " has been healed for " << n << " HP." << std::endl;

  m_zeroHp = false;
  if (m_currHp + n >= m_maxHp)
  {
    m_currHp = m_maxHp;
    std::cout << m_name << " is at maximum HP!" << std::endl;
  }
  else
  {
    m_currHp += n;
    std::cout << m_name << " has " << m_currHp << " HP now." << std::endl;
  }
};

void Adventurer::operator<<(std::string line)
{
  std::cout << m_name << ": " << line << std::endl;
};

void Adventurer::stats()
{
  if (m_isDead)
  {
    std::cout << m_name << " is dead." << std::endl;
    return;
  }

  std::cout << m_name << "'s current stats:" << std::endl;
  std::cout << "   Race: " << m_race << std::endl;
  std::cout << "   HP: " << m_currHp << "/" << m_maxHp << std::endl;
  std::cout << "   Stamina: " << m_currSta << "/" << m_maxSta << std::endl;
};

int Adventurer::attack()
{
  if (m_weapon || m_weapon->getLongRange() || m_weapon->getMagicAttack())
  {
    std::cout << m_name << " is still not able to use their weapon, instead they will make an unarmed strike!" << std::endl;
    std::cout << m_name << " hits for 2 damage!" << std::endl;
    return 2;
  }

  int damage = m_weapon->attack();
  std::cout << m_name << " hits for " << damage << " damage!" << std::endl;

  return damage;
}

void Adventurer::operator-=(int n)
{
  std::cout << m_name << " has taken " << n << " damage." << std::endl;

  if (n > m_maxHp || n > m_currHp)
    return die();

  if (n < m_currHp)
  {
    m_currHp -= n;
    std::cout << m_name << " has " << m_currHp << " HP now." << std::endl;
  }
  else if (n == m_currHp)
  {
    m_currHp = 0;
    m_zeroHp = true;
    std::cout << m_name << "'s life is hanging by a thread, they have been incapacitaded!" << std::endl;
    return;
  }

  if (m_currHp <= 3)
  {
    std::cout << m_name << " has taken massive damage in battle, they need to be healed!" << std::endl;
  }
};

void Adventurer::setStamina(int n)
{
  m_maxSta = m_currSta = n;
}

void Adventurer::setHP(int n)
{
  m_maxHp = m_currHp = n;
}

std::string Adventurer::getRace()
{
  return m_race;
}

std::string Adventurer::getName()
{
  return m_name;
}

Weapon Adventurer::getWeapon()
{
  return *m_weapon;
}

bool Adventurer::isDead()
{
  return m_isDead;
};

bool Adventurer::hasZeroHp()
{
  return m_zeroHp;
};

Adventurer *createHuman(std::string name)
{
  Weapon *club = createClub();
  Adventurer *adv = new Adventurer(10, 10, name, "Human", club);
  return adv;
}

Adventurer *createDwarf(std::string name)
{
  Weapon *club = createClub();
  Adventurer *adv = new Adventurer(15, 7, name, "Dwarf", club);
  return adv;
}

Adventurer *createElf(std::string name)
{
  Weapon *club = createClub();
  Adventurer *adv = new Adventurer(7, 15, name, "Elf", club);
  return adv;
}

Adventurer *createGrunt(int n)
{
  Weapon *club = createClub();
  Adventurer *adv = new Adventurer(7, 7, "Orc " + n, "Orc", club);
  return adv;
}