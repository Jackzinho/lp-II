#include "Cliente.hpp"

Cliente::Cliente(std::string nome)
{
  m_nome = nome;
}

void Cliente::setNome(std::string nome)
{
  m_nome = nome;
}

std::string Cliente::getNome()
{
  return m_nome;
}

std::string Cliente::toString()
{
  std::stringstream ss;
  ss << "nome: " << m_nome << std::endl;
  
  return ss.str();
}