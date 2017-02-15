#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

void test (const string& fileName){
    ifstream myFile;
    myFile.open(fileName.c_str());

    string theCode;
    myFile >> theCode;
    myFile.close();

    int amount = 0;
    for (int i = 0; i < theCode.size(); i+=2){
        int a;
        int r;
        int after;
        if (theCode[i] == '1'){
            a = 1;
        }
        else if (theCode[i] == '2'){
            a = 2;
        }
        else if (theCode[i] == '3'){
            a = 3;
        }
        else if (theCode[i] == '4'){
            a = 4;
        }
        else if (theCode[i] == '5'){
            a = 5;
        }
        else if (theCode[i] == '6'){
            a = 6;
        }
        else if (theCode[i] == '7'){
            a = 7;
        }
        else if (theCode[i] == '8'){
            a = 8;
        }
        else if (theCode[i] == '9'){
            a = 9;
        }
        else {
            a = 0;
        }
//cout << theCode[i] << endl;
        if (theCode[i+1] == 'I'){
            r = 1;
        }
        else if (theCode[i+1] == 'V'){
            r = 5;
        }
        else if (theCode[i+1] == 'X'){
            r = 10;
        }
        else if (theCode[i+1] == 'L'){
            r = 50;
        }
        else if (theCode[i+1] == 'C'){
            r = 100;
        }
        else if (theCode[i+1] == 'D'){
            r = 500;
        }
        else {
            r = 1000;
        }
        if (i+2 < theCode.size()){
            if (theCode[i+3] == 'I'){
                after = 1;
            }
            else if (theCode[i+3] == 'V'){
                after = 5;
            }
            else if (theCode[i+3] == 'X'){
                after = 10;
            }
            else if (theCode[i+3] == 'L'){
                after = 50;
            }
            else if (theCode[i+3] == 'C'){
                after = 100;
            }
            else if (theCode[i+3] == 'D'){
                after = 500;
            }
            else {
                after = 1000;
            }
//cout << theCode[i+1] << " " << theCode[i+3] << endl;
//cout << r << " " << after << endl;
            if (after > r){
    //            if (after != 5 && r !=  1 || after != 50 && r != 10 || after != 500 && r != 100){
                    a *= -1;
    //            }
            }
        }
//cout << a*r << endl;
        amount += a*r;
//cout << amount << endl << endl;
    }
    cout << amount << endl;
}

int main()
{
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2012\\TestFiles\\S2\\s2.1.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2012\\TestFiles\\S2\\s2.2.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2012\\TestFiles\\S2\\s2.3.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2012\\TestFiles\\S2\\s2.4.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2012\\TestFiles\\S2\\s2.5.in");

    return 0;
}
