#include "ContaEspecial.hpp"

ContaEspecial::ContaEspecial(std::string nomeCliente, float saldo, float limite)
{
  m_saldo = saldo;
  m_nomeCliente = nomeCliente;
  m_limite = limite;
}

bool ContaEspecial::sacar(float valor)
{
  if (m_saldo + m_limite < valor)
  {
    return false;
  }

  m_saldo -= valor;
  return true;
}

std::string ContaEspecial::toString()
{
  std::stringstream ss;
  float limiteAjustado = m_saldo < 0 ? m_limite - (m_saldo * -1) : m_limite;

  ss << "titular: " << m_nomeCliente << ", saldo: " << m_saldo << ", limite: " << limiteAjustado << std::endl;

  return ss.str();
}