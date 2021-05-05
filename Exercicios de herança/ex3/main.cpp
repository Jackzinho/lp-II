#include "Cliente.hpp"
#include "ContaCorrente.hpp"
#include "ContaEspecial.hpp"
#include <iostream>

using namespace std;

int main()
{
  Cliente cliente1("Matheus Rocha Jacks");
  Cliente cliente2("Carlos Eduardo Vitorino Gomes");

  ContaCorrente contac1(cliente1.getNome(), 1000);
  ContaCorrente contac2(cliente2.getNome(), 120);
  ContaEspecial contae1(cliente2.getNome(), 1000, 100);

  contac1.depositar(500);
  cout << contac1.toString();

  if (!contae1.sacar(1050))
  {
    cout << "Falha no saque, nao ha saldo nem limite!" << endl;
  }
  cout << contae1.toString();

  if (!contac2.sacar(120))
  {
    cout << "Falha no saque, nao ha saldo!" << endl;
  }
  contac2.toString();

  if (!contac2.transferir(contac1))
  {
    cout << "Falha na transferencia, nao ha saldo!" << endl;
  }

  return 0;
}
