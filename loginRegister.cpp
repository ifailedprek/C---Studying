#include <iostream>
#include <fstream>
using namespace std;

bool isLoggedIn()
{
    string username, password, un, pw;

    cout << "Enter username: "; cin >> username;
    cout << "Enter password: "; cin >> password;

    ifstream read("C:\\Coding Projects\\C++ Studying\\" + username + ".txt");
    getline(read, un);
    getline(read, pw);

    if (un == username && pw == password)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int choice;

    cout << "1: Login\n2: Register\nYour choice: "; cin >> choice;
    

    if (choice == 1)
    {
        bool status = isLoggedIn();

        if (!status)
        {
            cout << "False Login!" << endl;
            system("PAUSE");
            return 0;
        }

        else 
        {
            cout << "Successfully logged in!" << endl;
            system("PAUSE");
            return 1;
        }
    }

    else if (choice ==2)
    {
        string username, password;

        cout << "Select a username: "; cin >> username;
        cout << "Select a password: "; cin >> password;

        ofstream file;
        file.open("C:\\Coding Projects\\C++ Studying\\" + username + ".txt");
        file << username << endl << password;
        file.close();

        main();
    }

    /*int choice;
    int valid = 1; 
    string username, password;
    string newUser, newPass;
    string users[1];
    string passwords[1];
    
    cout << "Welcome to Kars Corp\n";

    while (valid == 1){
        cout << "1: Login\n2: Register\nYour choice: ";
        cin >> choice;
        if (choice == 1){
        cout << "Please enter your username: ";
        cin >> username;
        cout << "Please enter your password: ";
        cin >> password;
        valid = 0;
        }
        else if (choice == 2){
            cout << "Please enter a username for registration: ";
            cin >> newUser;
            cout << "Please enter your password for registration: ";
            cin >> newPass;
            cout << "Thank you for registering, now select login in the menu.\n";
        }
        else{
            cout << "Invalid choice, please try again.\n";
        }
    }*/
}