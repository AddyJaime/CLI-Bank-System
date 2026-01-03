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
  Bank_account cuenta_2 = {2, "Juan", 200};

  // guardo la cuenta en mi banco
  my_bank.accounts.push_back(cuenta_1);
  my_bank.accounts.push_back(cuenta_2);


 bool active_program = true;
 bool found = false;
 
 while (active_program)
 {

   cout << "Menu: " << "\n";
  // <-------------------------------------->
  cout << "1:Ver cuenta" << "\n";
  cout << "2: crear cuetna" << "\n";
  cout << "3:Salir" << "\n";

   int  user_number;
 cout << "Please enter a number to continue:  \n";
 cin >> user_number;
int ID;

 if (user_number == 1)
 {
  cout << "Please enter an id" << "\n";
  cin >> ID;

 for (int i = 0; i < my_bank.accounts.size(); i++)
 {
   if (ID == my_bank.accounts[i].account_id)
   {
     
     cout << "Account found: " << my_bank.accounts[i].user_name << "\n";
     found = true;
     break;
   } 

  } 
  
  if (!found)
  {
    cout << "Account not found \n";
  }
 }
 }
 

//   int ID = 2;
//   bool found = false;

// for (int i = 0; i < my_bank.accounts.size(); i++)
// {
//   if (ID == my_bank.accounts[i].account_id)
//   {
    
//     cout << "Account found: " << my_bank.accounts[i].user_name << "\n";
//     found = true;
//     break;
//   } 
  
// }

// if (!found)
// {
//   cout << "Account not found \n";
// }


  return 0;
}