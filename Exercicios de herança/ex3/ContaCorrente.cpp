#include "ContaCorrente.hpp"

ContaCorrente::ContaCorrente(std::string nomeCliente, float saldo)
{
  m_saldo = saldo;
  m_nomeCliente = nomeCliente;
}

void ContaCorrente::depositar(float valor)
{
  m_saldo += valor;
}

bool ContaCorrente::sacar(float valor)
{
  if (m_saldo < valor)
  {
    return false;
  }

  m_saldo -= valor;
  return true;
}

bool ContaCorrente::transferir(ContaCorrente conta)
{
  if (m_saldo <= 0) return false;

  conta.depositar(m_saldo);

  m_saldo = 0;

  return true;
}

std::string ContaCorrente::toString()
{
  std::stringstream ss;
  ss << "titular: " << m_nomeCliente << ", saldo: " << m_saldo << std::endl;

  return ss.str();
}