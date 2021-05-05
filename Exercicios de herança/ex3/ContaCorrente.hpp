#ifndef CONTACORRENTE_HPP
#define CONTACORRENTE_HPP

#include <string>
#include <sstream>

class ContaCorrente
{
protected:
  float m_saldo;
  std::string m_nomeCliente;

public:
  ContaCorrente(): m_nomeCliente(""), m_saldo(0) {};
  ContaCorrente(std::string nomeCliente, float saldo);
  
  void depositar(float valor);
  bool sacar(float valor);
  bool transferir(ContaCorrente conta);

  std::string toString();
};

#endif