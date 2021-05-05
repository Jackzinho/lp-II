#include "Specializations.hpp"

// Wizard {
void Wizard::stats()
{
  Adventurer::stats();

  std::cout << "   Max Mana: " << m_currMana << "/" << m_maxMana << std::endl;
};

int Wizard::attack()
{
  if (m_currMana <= 0)
  {
    std::cout << m_name << " has no mana!" << std::endl;
    return 0;
  }

  int damage = m_weapon->attack();
  m_currMana--;

  std::cout << m_name << " hits for " << damage << " damage!" << std::endl;
  std::cout << m_name << " has " << m_currMana << " mana now!" << std::endl;

  return damage;
}

Wizard *createWizard(Adventurer &adv)
{
  Weapon *staff = createStaff();
  if (adv.getRace() == "Human")
  {
    Wizard *ad = new Wizard(20, adv, staff);
    ad->setStamina(8);

    return ad;
  }
  else if (adv.getRace() == "Dwarf")
  {
    Wizard *ad = new Wizard(7, adv, staff);
    ad->setStamina(5);

    return ad;
  }
  else if (adv.getRace() == "Elf")
  {
    Wizard *ad = new Wizard(12, adv, staff);
    ad->setStamina(10);

    return ad;
  }
};
// } Wizard

// Ranger {
void Ranger::stats()
{
  Adventurer::stats();

  std::cout << "   Max Ammo: " << m_currAmmo << "/" << m_maxAmmo << std::endl;
};

int Ranger::attack()
{
  if (m_currAmmo <= 0)
  {
    std::cout << m_name << " has no ammo!" << std::endl;
    return 0;
  }

  int damage = m_weapon->attack();
  m_currAmmo--;

  std::cout << m_name << " hits for " << damage << " damage!" << std::endl;
  std::cout << m_name << " has " << m_currAmmo << " ammo now!" << std::endl;

  return damage;
};

Ranger *createRanger(Adventurer &adv)
{
  Weapon *bow = createBow();
  if (adv.getRace() == "Human")
  {
    Ranger *ad = new Ranger(30, adv, bow);
    ad->setStamina(17);

    return ad;
  }
  else if (adv.getRace() == "Dwarf")
  {
    Ranger *ad = new Ranger(30, adv, bow);
    ad->setStamina(12);

    return ad;
  }
  else if (adv.getRace() == "Elf")
  {
    Ranger *ad = new Ranger(30, adv, bow);
    ad->setStamina(25);

    return ad;
  }
};
// } Ranger

// Fighter {
void Fighter::stats()
{
  Adventurer::stats();

  std::cout << "   Max Damage Dies: " << m_currDmgDie << "/" << m_maxDmgDie << std::endl;
};

int Fighter::attack()
{
  std::string useDmgDie;
  int damage = 0;

  if (m_currDmgDie > 0)
  {
    do
    {
      std::cout << "Does " << m_name << " wish to use a Damage Die and improve their damage? (y/n)" << std::endl;
      std::cin >> useDmgDie;
    } while (useDmgDie != "y" && useDmgDie != "n");

    if (useDmgDie == "y")
    {
      damage += rand() % 6 + 1; 
      m_currDmgDie--;
      std::cout << m_name << " has " << m_currDmgDie << " Damage Dies now!" << std::endl;
    }
  }

  damage += m_weapon->attack();

  std::cout << m_name << " hits for " << damage << " damage!" << std::endl;

  return damage;
}

Fighter *createFighter(Adventurer &adv)
{
  Weapon *sword = createSword();
  if (adv.getRace() == "Human")
  {
    Fighter *ad = new Fighter(5, adv, sword);
    ad->setStamina(12);
    ad->setHP(12);

    return ad;
  }
  else if (adv.getRace() == "Dwarf")
  {
    Fighter *ad = new Fighter(15, adv, sword);
    ad->setStamina(14);
    ad->setHP(25);

    return ad;
  }
  else if (adv.getRace() == "Elf")
  {
    Fighter *ad = new Fighter(10, adv, sword);
    ad->setStamina(17);
    ad->setHP(13);

    return ad;
  }
}
// } Fighter