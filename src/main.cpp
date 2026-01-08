#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

// =======================================================
// 🧾 Represents a SINGLE bank account
// =======================================================
struct Bank_account
{
    int account_id;
    string user_name;
    double balance;
};

// =======================================================
// 🏦 Represents the bank as an entity
// The bank OWNS multiple accounts
// =======================================================
struct Bank
{
    string bank_name;
    vector<Bank_account> accounts;
};

int main()
{
    // ===================================================
    //  🏦 Create bank
    // ===================================================
    Bank my_bank;
    my_bank.bank_name = "Popular";

    // ===================================================
    //🧾 Initial accounts (seed data)
    // ===================================================
    Bank_account cuenta_1 = {1, "Addy Jaime", 100};
    Bank_account cuenta_2 = {2, "Juan", 200};

    my_bank.accounts.push_back(cuenta_1);
    my_bank.accounts.push_back(cuenta_2);

    // ===================================================
     //🔄 Program state
    // ===================================================
    bool active_program = true;

    while (active_program)
    {
        // ===================================================
        //  📋 MAIN MENU
        // ===================================================
        cout << "\n==============================\n";
        cout << "🏦 BANK MENU\n";
        cout << "\n============================\n";
        cout << "1️⃣: View account\n";
        cout << "2️⃣: Create account\n";
        cout << "3️⃣: Deposit money\n";
        cout << "4️⃣: Withdraw\n";   
        cout << "5️⃣: Exit\n";
        cout << "\n==============================\n";
        cout << "👉 Select an option: ";

        int user_option;
        cin >> user_option;

        // ===================================================
        // 🔍 OPTION 1: VIEW ACCOUNT
        // ===================================================
        if (user_option == 1)
        {
            bool found = false;

            int ID;
            cout << "\n 🧾Enter account ID: ";
            cin.ignore();
            cin >> ID;

            for (int i = 0; i < my_bank.accounts.size(); i++)
            {
                if (my_bank.accounts[i].account_id == ID)
                {
                    cout << "\n✅Account found:\n";
                    cout << "👤 Name: " << my_bank.accounts[i].user_name << "\n";
                    cout << "💰 Balance: $" << my_bank.accounts[i].balance << "\n";
                    found = true;
                    break;
                }
            }

            if (!found)
            {
                cout << "\nAccount not found. Returning to menu: \n";
            }
        } 

        // ===================================================
        // ⌥ OPTION 2: CREATE ACCOUNT (NAME VALIDATION)
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
                cout << "\n✍️  Enter full name:  ";
                getline(cin, user_name);

                valid_name = true;

                // Rule 1️⃣: minimum length
                if (user_name.length() < 2)
                {
                    valid_name = false;
                }

                // Rule 2️⃣: only letters and spaces 
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
                    cout << "❌ Invalid name. Try again.\n";
                }
            }
            //🧠 System decisions 
            double  balance = 0;
            int new_id = my_bank.accounts.size() + 1;
            
            // Create and store account
            Bank_account cuenta_3 = {new_id, user_name, balance};
            my_bank.accounts.push_back(cuenta_3);

            // ✅Confirmation 
            cout << "\n Account created successfully!\n" << endl;
            cout << "🆔 Account_id:  " << new_id << endl;
            cout << "👤 Name : " << user_name << endl;
            cout << "💰 Balance: $" << balance << endl;
            
        } 

        // ================================ 
        // 💰 DEPOSIT MONEY
        // ================================
        else if (user_option == 3)
        {
            int ID;
            bool found = false;
            double amount;

            cout << "\n 🧾Account verification — enter account ID: ";
            cin >> ID;
            // El loop se detiene solo cuando ya no hay más cuentas
            for (int i = 0; i < my_bank.accounts.size(); i++)
            {
                if (my_bank.accounts[i].account_id == ID)
                {
                    found = true;
                    cout << "\n Account found \n";
                    cout << "👤 Name : " << my_bank.accounts[i].user_name << endl;
                    cout << "💰 Balance: $" << my_bank.accounts[i].balance << endl;
                    cout << "\n=====================\n";
                    cout << "💰 Enter deposit amount: ";
                    cin >> amount;

                    if (amount > 0)
                    {
                        my_bank.accounts[i].balance += amount;
                        cout << "\n======================================= \n";
                        cout << " | 💸 Deposit Successful: " << endl;
                        cout << " | 👤 User: " << my_bank.accounts[i].user_name << " \n";
                        cout << " | 💰 New Balance: " << my_bank.accounts[i].balance << "$ \n";
                       }
                       else {
                        cout << "❌ Invalid amount. Operation cancelled.\n";
                       }
                       break;
                    
                    
                }

            }
            if (!found)
            {
                 cout << "❌ Account not found. Returning to menu.\n";
            }
        }



        // ==============================
        // 💸 WITHDRAW MONEY
        // ==============================
       
        else if(user_option == 4){
            int ID;
            bool found = false;
            double amount;

            cout << "\n 🧾Account verification — enter account ID: ";
            cin >> ID;

            for (int i = 0; i < my_bank.accounts.size(); i++)
            {
                if (ID == my_bank.accounts[i].account_id)
                {
                    found = true;
                    cout << "👤 User: " << my_bank.accounts[i].user_name << " \n";
                    cout << "💰 Current balance: " << my_bank.accounts[i].balance << "$ \n";
                    cout << "💸 Enter withdrawal amount : ";
                    cin >> amount;

                    if (amount > 0 && amount <= my_bank.accounts[i].balance)
                    {
                        my_bank.accounts[i].balance -= amount;
                        cout << "\n======================================= \n";
                        cout << " | 💸 WITHDRAW SUCCESSFULl: " << endl;
                        cout << " | 💰 New Balance: " << my_bank.accounts[i].balance << "$ \n";
                         cout << "\n======================================= \n";
                } else 
                {
                     cout << "❌ Invalid amount or insufficient funds.\n";
                }
                break;
              
                
            }
            
             
                }


               if (!found)
               {
                cout << "❌ Account not found. Returning to menu.\n";
               }
               
                }


        // ==============================
        // 🚪 EXIT
        // ==============================

        else if (user_option == 5)
                {
            cout << "\n👋 Thank you for using the bank system. Goodbye!\n";
            active_program = false;

        }
            // ==============================
        // ❌ INVALID OPTION
        // ==============================          
            else {
              cout << "\nInvalid option. Try again.\n";
          }
            
        }
        return 0;
    } 


