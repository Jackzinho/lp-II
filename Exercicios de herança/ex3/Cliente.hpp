#ifndef CLIENTE_HPP
#define CLIENTE_HPP

#include <string>
#include <sstream>

class Cliente
{
private:
  std::string m_nome;

public:
  Cliente(): m_nome("") {};
  Cliente(std::string nome);

  void setNome(std::string nome);
  std::string getNome();

  std::string toString();
};

#endif