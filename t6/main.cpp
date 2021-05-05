#include "Adventurer.hpp"
#include "Specializations.hpp"
#include <cstdlib>
#include <string>
#include <sstream>
#include <ctime>
#include <vector>

using namespace std;

// void slowPrint(string s);

int main()
{
  srand(time(NULL));
  vector<Adventurer *> characters;

  cout << "You will be able to create 3 characters, choose wisely..." << endl
       << endl;

  for (int i = 1; i <= 3; i++)
  {
    string choice;
    Adventurer *character;

    cout << "Character number " << i << endl;

    do
    {
      cout << "Choose between 3 races:" << endl;
      cout << "   Dwarf" << endl;
      cout << "   Elf" << endl;
      cout << "   Human" << endl;
      cout << "Your choice: " << endl;
      cin >> choice;

    } while (choice != "Dwarf" && choice != "Human" && choice != "Elf");

    if (choice == "Dwarf")
    {
      string name;

      cout << "Name the dwarf: " << endl;
      cin >> name;

      character = createDwarf(name);
    }
    else if (choice == "Elf")
    {
      string name;

      cout << "Name the elf: " << endl;
      cin >> name;

      character = createElf(name);
    }
    else if (choice == "Human")
    {
      string name;

      cout << "Name the human: " << endl;
      cin >> name;

      character = createHuman(name);
    }

    do
    {
      cout << "Choose between 3 classes:" << endl;
      cout << "   Fighter" << endl;
      cout << "   Ranger" << endl;
      cout << "   Wizard" << endl;
      cout << "Your choice: " << endl;
      cin >> choice;

    } while (choice != "Fighter" && choice != "Ranger" && choice != "Wizard");

    if (choice == "Fighter")
      characters.push_back(createFighter(*character));
    else if (choice == "Ranger")
      characters.push_back(createRanger(*character));
    else if (choice == "Wizard")
      characters.push_back(createWizard(*character));
  }

  cout << endl;

  for (Adventurer *adv : characters)
  {
    adv->stats();
  }

  cout << endl;

  int killCount = 0;
  int enemyCount = 3;

  while (characters.size() != 0)
  {
    vector<Adventurer *> grunts;

    for (int i = 1; i <= enemyCount; i++)
    {
      grunts.push_back(createGrunt(i));
    }

    cout << "The adventurers have encountered " << enemyCount << " orcs, it seems like they want to fight!";

    while (grunts.size() != 0)
    {
      for (Adventurer *adv : characters)
      {
        cout << "It's " << adv->getName() << "'s turn!" << endl;
      }
    }

    break;

    enemyCount++;
  }

  return 0;
}

// void slowPrint(string s)
// {
//   for (char c : s)
//   {
//     this_thread::sleep_for(chrono::milliseconds(100));
//     cout << c << flush << endl;
//   }
// }
