#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int fractorial (int theNumber){
    int number = theNumber;
    bool found;
    while (true){
        found = true;
        for (int i = 1; i < theNumber; i++){
            if (number%i != 0) {
                found = false;
                break;
            }
        }
        if (found == true){
            return number;
        }
        number += theNumber;
    }
}

void test (const string& fileName){
    ifstream myFile;
    myFile.open(fileName.c_str());

    int theNumber;
    for (int i = 0; i < 5; i++){
        myFile >> theNumber;
        cout << "Fractorial (" << theNumber << ") = " << fractorial(theNumber) << endl;
    }
    myFile.close();
}

int main()
{
    test ("C:\\Users\\ayuan\\Documents\\Computer\\ECOO\\ECOO 2005\\TEST11.txt");
    return 0;
}
