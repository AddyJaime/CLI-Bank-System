#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

// =======================================================
// Representa UNA cuenta bancaria individual
// =======================================================
struct Bank_account
{
    int account_id;
    string user_name;
    double balance;
};

// =======================================================
// Representa el banco como entidad
// =======================================================
struct Bank
{
    string bank_name;
    vector<Bank_account> accounts;
};

int main()
{
    // ===================================================
    // Crear banco
    // ===================================================
    Bank my_bank;
    my_bank.bank_name = "Popular";

    // ===================================================
    // Cuentas iniciales
    // ===================================================
    Bank_account cuenta_1 = {1, "Addy Jaime", 100};
    Bank_account cuenta_2 = {2, "Juan", 200};

    my_bank.accounts.push_back(cuenta_1);
    my_bank.accounts.push_back(cuenta_2);

    // ===================================================
    // Programa activo
    // ===================================================
    bool active_program = true;

    while (active_program)
    {
        // ===================================================
        // MENU PRINCIPAL
        // ===================================================
        cout << "\nMenu:\n";
        cout << "1: Ver cuenta\n";
        cout << "2: Crear cuenta\n";

        int user_option;
        cout << "Choose an option: ";
        cin >> user_option;

        // ===================================================
        // OPCIÓN 1: VER CUENTA
        // ===================================================
        if (user_option == 1)
        {
            bool found = false;

            int ID;
            cout << "Enter account ID: ";
            cin >> ID;

            for (int i = 0; i < my_bank.accounts.size(); i++)
            {
                if (my_bank.accounts[i].account_id == ID)
                {
                    cout << "\nAccount found\n";
                    cout << "Name: " << my_bank.accounts[i].user_name << "\n";
                    cout << "Balance: " << my_bank.accounts[i].balance << "\n";

                    found = true;
                    break;
                }
            }

            if (!found)
            {
                cout << "\nAccount not found\n";
            }
        } // aqui termina el if de la opcion 1

        // ===================================================
        // OPCIÓN 2: CREAR CUENTA (VALIDAR NOMBRE)
        // ===================================================
        else if (user_option == 2)
        {
          // Cuando el usuario escribe "2" y presiona ENTER, en el buffer quedan dos cosas:
          // el número '2' y el caracter ENTER ('\n').
          // cin >> user_option lee SOLO el número 2 y deja el ENTER sobrando.
          // cin.ignore() elimina ese ENTER viejo del buffer.
          // Así el buffer queda limpio y getline puede esperar correctamente
          // a que el usuario escriba el nombre.

            cin.ignore(); 

            string user_name;
            bool valid_name = false;

            while (!valid_name)
            {
                cout << "\nPlease enter your first and last name: ";
                getline(cin, user_name);

                valid_name = true;

                // Regla 1: longitud mínima
                if (user_name.length() < 2)
                {
                    valid_name = false;
                }

                // Regla 2: solo letras y espacios
                for (char c : user_name)
                {
                  // esto pregunta si c es una letra. y tamibrn si c no es un espacio
                  // Si el carácter NO es una letra Y tampoco es un espacio entonces es inválido
                    if (!isalpha(c) && c != ' ')
                    {
                        valid_name = false;
                    }
                }

                if (!valid_name)
                {
                    cout << "❌ Name incorrect. Try again.\n";
                }
            }

            cout << "✅ Name correct: " << user_name << endl;
        } // aqui termina el if de la op[cion 2]

        // ===================================================
        // OPCIÓN INVÁLIDA
        // ===================================================
        else
        {
            cout << "\nInvalid option. Try again.\n";
        }
    }

    return 0;
}
