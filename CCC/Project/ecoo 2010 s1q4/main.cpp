#include <iostream>
#include <fstream>
#include <map>

using namespace std;

map<char,int> rSymbol;

string numberToRoman (int number){
    string romanSymbol = "";
    while (number > 0){
        if (number >= 1000) {
            number -= 1000;
            romanSymbol += "M";
        }
        else if (number >= 500) {
            number -= 500;
            romanSymbol += "D";
        }
        else if (number >= 100) {
            number -= 100;
            romanSymbol += "C";
        }
        else if (number >= 50) {
            number -= 50;
            romanSymbol += "L";
        }
        else if (number >= 10) {
            number -= 10;
            romanSymbol += "X";
        }
        else if (number >= 5) {
            number -= 5;
            romanSymbol += "V";
        }
        else if (number >= 1) {
            number -= 1;
            romanSymbol += "I";
        }
    }
    return romanSymbol;
}

void romanToNumber (string letters, int& number){
    number = 0;
    for (int i = 0; i < letters.length(); i++){
        number += rSymbol[letters[i]];
    }
}

void test (const string& fileName) {

    ifstream myFile;
    myFile.open(fileName.c_str());
    for (int i = 0; i < 5; i++){
        string one, two;
        myFile >> one >> two;
        int nOne, nTwo;
        romanToNumber (one, nOne);
        romanToNumber (two, nTwo);

        cout << one << " + " << two << " = " << numberToRoman(nOne+nTwo) << endl;
    }
    myFile.close();
}

int main()
{
    rSymbol['I'] = 1;
    rSymbol['V'] = 5;
    rSymbol['X'] = 10;
    rSymbol['L'] = 50;
    rSymbol['C'] = 100;
    rSymbol['D'] = 500;
    rSymbol['M'] = 1000;

    test ("C:\\Users\\ayuan\\Documents\\Computer\\Project\\TestFiles\\DATA3.txt");
    return 0;
}
