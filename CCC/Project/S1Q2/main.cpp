#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

double letterToNumber (char a){
    if (a == '.') {
//cout << "the letter is: . the code is: 0"<< endl;
        return 0;
    }
    else {
//cout << "the letter is: " << a << " the code is: " << int(a) - 64 << endl;
        return int(a) - 64;
    }
}

double power (int base, int exp){
    int result = 1;
    for (int i = 0; i < exp; i++){
        result *= base;
    }
    return result;
}

struct Base27Code {
    int number [5];
    void readCode (){
        for (int i = 0; i < 5; i++) {
            if (number[i] == 0) cout << ".";
            else cout << char(number[i]+64);
        }
    }

    void setValue (string theCode, int key){
        int codeNumber = 0;
        for (int i = 0; i < 5; i++){
            codeNumber += letterToNumber(theCode[4-i]) * power(27,i);
        }
cout << "the key is " << key << endl;
cout << "the code " << theCode << " is " << codeNumber << endl;

        codeNumber -= key;
//cout << "the code number for " << theCode << " is " << codeNumber << endl;
        for (int i = 0; i < 5; i++){
            number[i] = floor(codeNumber/power(27.000,4.000-i));
//cout << floor(codeNumber/pow(27.000,4.000-i)) << endl;

            codeNumber -= number[i]* power(27.000,4.000-i);

//cout << codeNumber << endl;
        }
        number[4] = codeNumber;
//cout << "the base  27 is: ";
//for (int i = 0; i < 5; i++) {
//    cout << number[i] << ", ";
//} cout << endl;
    }
};

void test (const string& fileName) {
    ifstream myFile;
    myFile.open (fileName.c_str());
    for (int testCases = 0; testCases < 1; testCases++){
        string keyWord;
        string theCode;
        myFile >> keyWord >> theCode;
        vector<Base27Code> codes;

        int key = 0;
        for (int i = 0; i < keyWord.length(); i++){
            key += letterToNumber(keyWord[keyWord.length()-i-1]) * pow(27,i);
        }
        Base27Code valueHolder;
        for (int i = 4; i < theCode.size(); i+=5){
            valueHolder.setValue(theCode.substr(i-4,5), key);
            codes.push_back(valueHolder);
        }
        for (int i = 0; i < codes.size(); i++){
            codes[i].readCode();
        }cout << endl;
    }

    myFile.close();
}

int main()
{
    test ("C:\\Users\\ayuan\\Documents\\Computer\\Project\\TestFiles\\DATA2.txt");
//    cout << floor(4786304/pow(27,4)) << endl;
//    cout << 4786304 - 9*pow(27,4) << endl;
//
//    cout << floor(3335/pow(27,3)) << endl;
//    cout << 3335 - 0*pow(27,3) << endl;
//
//    cout << floor(3335/pow(27,2)) << endl;
//    cout << 3335 - 4*pow(27,2) << endl;
//
//    cout << floor(419/pow(27,1)) << endl;
//    cout << 419 - 15*pow(27,1) << endl;
    return 0;
}
