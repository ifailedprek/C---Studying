#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
    ifstream readFile("C:\\Coding Projects\\C++ Studying\\test.txt");
    string readout,
           search,
           firstname,
           lastname;

    cout << "Enter the id which you want to modify";
    cin >> search;

    while(getline(readFile,readout)){
        if(readout == search){
            /*
                id remains the same
                But the First name and Last name are replaced with
                the user `firstname` and `lastname` input
            */
            cout << "Enter new First name";
            cin >> firstname;

            cout << "Enter Last name";
            cin >> lastname;  
        }
    }
}  