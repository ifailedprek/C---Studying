#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
using namespace std;

void login();
void registration();
void forgot();

int main()
{
    system("cls");
    int choice;
    cout << "Test.";

    cout << "\t\t\t_____________________________________________\n";
    cout << "\t\t\tWelcome to the new and improved Login System!\n";
    cout << "\t\t\t_____________________________________________\n";
    cout << "\t\t\t\tHow can I help you today?\n\t\t\t\t1. Login\n\t\t\t\t";
    cout << "2. Register\n\t\t\t\t3. Forgot\n\t\t\t\t";
    cout << "Your Choice: ";
    cin >> choice;

    switch(choice)
    {
        case 1:
        {
            system("cls");
            login();
            main();
            break;
        }
        case 2:
        {
            system("cls");
            registration();
            main();
            break;
        }
        case 3:
        {
            system("cls");
            forgot();
            main();
            break;
        }
        default:
        {
            system("cls");
            cout << "Invalid input.";
            main();
        }
    }
}

void login()
{
    int count = 0;
    string username, password, un, pw;
    
    cout << "\t\t\t\tEnter username: "; cin >> username;
    cout << "\t\t\t\tEnter password: "; cin >> password;

    ifstream file("C:\\Coding Projects\\C++ Studying\\users.txt");

    while (file >> un >> pw)
    {
        if (un == username && pw == password)
        {
            count = 1;
            system("cls");
        }
    }
    file.close();

    if (count == 1)
    {
        cout << "\t\t\t\tSuccessful login! Welcome, " << username << ".\n\n";
        system("pause");
    }
    else
    {
        cout << "\t\t\t\tUnsuccessful login! Please try again.\n\n";
        system("pause");
    }
}

void registration()
{
    string rUsername, rPassword, rUn, rPw;
    
    cout << "\t\t\t\tSelect username: "; cin >> rUsername;
    cout << "\t\t\t\tSelect password: "; cin >> rPassword;

    ofstream f1("C:\\Coding Projects\\C++ Studying\\users.txt", ios::app);
    f1 << rUsername << " " << rPassword << endl;
    system("cls");
    cout << "\t\t\t\tRegistration Successful!\n\n";
    system("pause");
}

void forgot()
{
    int choice;
    cout << "\t\t\t\tWe can help you find your forgotten password,";
    cout << "\n\t\t\t\tor help change it.\n\t\t\t\t";
    cout << "1. Search for password by username\n\t\t\t\t2. Change password\n\t\t\t\t";
    cout << "3. Go back to main menu\n\n\t\t\t\tYour Choice: "; cin >> choice;
    

    switch (choice)
    {
        case 1:
        {
            int count = 0;
            string sUsername, sUn, sPassword;
            cout << "\t\t\t\tEnter a username to search the database: "; cin >> sUsername;
            ifstream f2("C:\\Coding Projects\\C++ Studying\\users.txt");
            
            while (f2 >> sUn >> sPassword)
            {
                if (sUsername == sUn)
                {
                    count = 1;
                    break;
                }
            }
            f2.close();
            if (count == 1)
            {
                cout << "\t\t\t\tYour username was found in the database.\n\n";
                cout << "\t\t\t\tUsername: " << sUsername << "\n\t\t\t\tPassword: ";
                cout << sPassword << endl;
                system("pause");
                main();
            }
            else 
            {
                cout << "\t\t\t\tYour username was not found in the database.";
                system("pause");
                main();
            }
            break;
        }
        case 2:
        {
            // int count = 0;
            string cUsername, cUn, cPassword, cPw, read;
            cout << "\t\t\t\tEnter a username to search the database: "; cin >> cUsername;

            fstream f3("C:\\Coding Projects\\C++ Studying\\users.txt");
            
            while (f3 >> cUn >> cPw)
            {
                if (cUsername == cUn)
                {
                    // count = 1;
                    cout << "\t\t\t\tYour username was found in the database.\n\n";
                    cout << "\t\t\t\tPlease enter new password: "; cin >> cPassword;
                    // fstream f4("C:\\Coding Projects\\C++ Studying\\users.txt");
                    f3 << cUsername << " " << cPassword << endl;
                    system("cls");
                    cout << "\t\t\t\tPassword Changed Successful!\n\n";
                    break;
                }
            }
            f3.close();
            system("pause");
            break;
        }
        case 3:
        {
            main();
        }
        default:
        {
            system("cls");
            cout << "\t\t\t\tPlease select from the given options.";
            forgot();
        }
    }
}