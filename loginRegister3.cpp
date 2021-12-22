#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

void login();
void registration();
void forgot();

int main()
{
    int choice;
    cout << "\nWelcome to the login page.\n";
    cout << "1. Login\n2. Register\n3. Forgot\n4. Exit\nYour Choice: ";
    cin >> choice;

    switch(choice)
    {
        case 1:
            login ();
            break;
        case 2:
            registration();
            break;
        case 3:
            forgot();
            break;
        case 4:
            cout << "Goodbye.\n";
            break;
        default:
            system("cls");
            cout << "Please select from the given options.\n";
            main();
    }
}

void login()
{
    int count = 0;
    string username, password, un, pw;
    system("cls");
    cout << "Enter username: "; cin >> username;
    cout << "Enter password: "; cin >> password;

    ifstream users("C:\\Coding Projects\\C++ Studying\\users.txt");

    while (users >> un >> pw)
    {
        if (username == un && password == pw)
        {
            count = 1;
            system("cls");
        }
    }
    users.close();

    if (count == 1)
    {
        cout << "\nWelcome " << username << ", your login is successful.\n\n";
        main();
    }
    else
    {
        cout << "Username/Password is invalid.\n";
        main();
    }
}

void registration()
{
    string rUsername, rPassword, rUn, rPw;
    system("cls");
    cout << "Select username: "; cin >> rUsername;
    cout << "Select password: "; cin >> rPassword;

    ofstream f1("C:\\Coding Projects\\C++ Studying\\users.txt", ios::app);
    f1 << rUsername << " " << rPassword << endl;
    system("cls");
    cout << "Registration is successful.\n";
    main();
}

void forgot()
{
    int option;
    system("cls");
    cout << "1. Search by username\n2. Go back to main menu\nYour Choice: ";
    cin >> option;

    switch(option)
    {
        case 1:
        {
            int count = 0;
            string sUsername, sUn, sPassword, tempPass;
            cout << "Enter username: "; cin >> sUsername;

            ifstream f2("C:\\Coding Projects\\C++ Studying\\users.txt");
            while (f2 >> sUn >> sPassword)
            {
                if (sUsername == sUn)
                {
                    count = 1;
                    // tempPass = sPassword;// Check why it's reading up to last line
                    break;
                }
            }
            f2.close();
            if (count == 1)
            {
                cout << "Username was found.\nYour password is: " << sPassword;
                main();
            }
            else
            {
                cout << "Username not found.\n";
                main();
            }
            break;
        }
        case 2:
        {
            main();
        }
        default:
        {
            system("cls");
            cout << "Please select from the given options.\n";
            main();
        }
    }
}