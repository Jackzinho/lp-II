#include "person.hpp"

void LoadDatabase(string path, vector<pessoaF> &PF, vector<pessoaJ> &PJ)
{
  ifstream filereader;

  filereader.open(path);

  if (!filereader.is_open())
  {
    throw string("File could not be read!");
  }

  string str;

  while (getline(filereader, str))
  {
    if (str == "1") 
    {
      pessoaF p;

      getline(filereader, p.nome);
      getline(filereader, p.nomeMae);
      getline(filereader, p.cpf);
      getline(filereader, p.endereco);
      getline(filereader, p.telefone);

      PF.push_back(p);
    }
    else if (str == "2") 
    {
      pessoaJ p;
      string capital;

      getline(filereader, p.razaoSocial);
      getline(filereader, p.cnpj);
      getline(filereader, p.endereco);
      getline(filereader, p.telefone);
      getline(filereader, capital);

      p.capitalSocial = stoi(capital);

      PJ.push_back(p);
    }
  }

  filereader.close();
}

void SaveDatabase(string path, const vector<pessoaF> &PF, const vector<pessoaJ> &PJ)
{
  ofstream filereader;

  filereader.open(path);

  if (!filereader.is_open())
  {
    throw string("File could not opened!");
  }

  for (pessoaF p : PF) {
    filereader << 1 << endl;
    filereader << p.nome << endl;
    filereader << p.nomeMae << endl;
    filereader << p.cpf << endl;
    filereader << p.endereco << endl;
    filereader << p.telefone << endl;
  }

  for (pessoaJ p : PJ) {
    filereader << 2 << endl;
    filereader << p.razaoSocial << endl;
    filereader << p.cnpj << endl;
    filereader << p.endereco << endl;
    filereader << p.telefone << endl;
    filereader << p.capitalSocial << endl;
  }

  filereader.close();

}