#include <iostream>
#include <vector>
#include <string>
using namespace std;

// =======================================================
// Representa UNA cuenta bancaria individual
// Guarda únicamente información, no ejecuta acciones
// =======================================================
struct Bank_account
{
  int account_id;
  string user_name;
  double balance;
};

// =======================================================
// Representa el banco como entidad
// El banco no es una cuenta, el banco POSEE cuentas
// =======================================================
struct Bank
{
  string bank_name;

  // Colección de cuentas bancarias
  // Este vector permite almacenar múltiples cuentas
  // Todas las cuentas son del tipo Bank_account
  vector<Bank_account> accounts;

  
};

int main()
{
  // crear un banco
  Bank my_bank;
  my_bank.bank_name = "Popular";

  // creo la cuenta
  Bank_account cuenta_1 = {1, "Addy Jaime", 100};

  // guardo la cuenta en mi banco
  my_bank.accounts.push_back(cuenta_1);

  cout << "ID " << my_bank.accounts[0].account_id << "\n";
  cout << "Name " << my_bank.accounts[0].user_name << "\n";
  cout << "Balance " << my_bank.accounts[0].balance << "\n";
  return 0;
}