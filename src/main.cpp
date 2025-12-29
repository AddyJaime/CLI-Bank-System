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


int main(){
  cout << "Hello world \n";
  return 0;
}