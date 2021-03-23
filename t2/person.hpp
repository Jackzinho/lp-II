#ifndef PERSON_HPP
#define PERSON_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct pessoaF
{
  string nome; 
  string nomeMae; 
  string cpf; 
  string endereco;
  string telefone;
};

struct pessoaJ
{
  string razaoSocial;
  string cnpj;
  string endereco;
  string telefone;

  size_t capitalSocial;
};

void LoadDatabase(string path, vector<pessoaF> &PF, vector<pessoaJ> &PJ);
void SaveDatabase(string path, const vector<pessoaF> &PF, const vector<pessoaJ> &PJ);

#endif
