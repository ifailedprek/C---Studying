#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int searchString(fstream &, string);

int main()
{
    string filename;
    string look;
    fstream infile("C:\\Coding Projects\\C++ Studying\\users.txt");

    cout << "What do you want to search in the text file? ";
    cin >> look;
    cout << "Beginning to search for " << look << endl;
    cout << look << " was found in " << searchString(infile, look) << " lines." << endl;

    infile.close();
    return 0;
}

int searchString(fstream &infile, string see)
    {
        string input;
        int count=0;
        int number=0;
        while(getline(infile,input))
        {
            number++;
            cout << "Line " << number << ": " << input << endl;
            if(input.find(see,0)!=string::npos)
            {
                cout << "found " << see << " in line " << number << endl;
                count++;
            }
        else
        {
            break;
        }
    }
    return count;
}