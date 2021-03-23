#include "person.hpp"

int main(int argc, char const *argv[])
{
  pessoaF pf;
  pessoaJ pj;

  vector<pessoaF> PFV;
  vector<pessoaJ> PJV;

  LoadDatabase("database.dat", PFV, PJV);

  SaveDatabase("database.dat", PFV, PJV);

  return 0;
}
