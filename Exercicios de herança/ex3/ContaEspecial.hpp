#ifndef CONTAESPECIAL_HPP
#define CONTAESPECIAL_HPP

#include <string>
#include <sstream>
#include "ContaCorrente.hpp"

class ContaEspecial : public ContaCorrente
{
private:
  float m_limite;

public:
  ContaEspecial(std::string nomeCliente, float saldo, float limite);
  
  bool sacar(float valor);

  std::string toString();
};

#endif