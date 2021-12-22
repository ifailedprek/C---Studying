#include <iostream>
#include <fstream>
using namespace std;

bool isLoggedIn()
{
    string username, password, un, pw;

    cout << "Enter username: "; cin >> username;
    cout << "Enter password: "; cin >> password;

    ifstream read("C:\\Coding Projects\\C++ Studying\\users.txt");
    getline(read, un);
    getline(read, pw);
    
    string line;
    size_t pos;
    int count = 0;
    while (getline(read, line))
    {
        count++;
        pos = line.find(username);
        if (pos != string::npos)
        {
            cout << "Username is on line " << count << endl;
            
            // break;
        }
    }

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
    cout << "Welcome!\n";

    int choice;

    cout << "1. Login\n2. Register\nYour choice: "; cin >> choice;

    if (choice == 1)
    {
        bool status = isLoggedIn();

        if (!status)
        {
            cout << "Failed login.\n";
            system("PAUSE");
            return 0;
        }
        else
        {
            cout << "Successful login!\n";
            system("PAUSE");
            return 1;
        }
    }
    else if (choice == 2)
    {
        string username, password;

        cout << "Select a username: "; cin >> username;
        cout << "Select a password: "; cin >> password;

        ofstream file;
        file.open("C:\\Coding Projects\\C++ Studying\\users.txt");
        file << username << endl << password;
        file.close();

        main();
    }
}