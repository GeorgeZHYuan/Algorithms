#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Letter {
public:
    char letter;
    string code;
};

string decypher (string theCode, Letter letters [], int numberOfLetters);
// void sortList (Letter *letters, int numberOfLetters);

void test (const string& fileName){
    ifstream myFile;
    myFile.open(fileName.c_str());

    int numberOfLetters;
    myFile >> numberOfLetters;

    Letter letters [numberOfLetters];

    for (int i = 0; i < numberOfLetters; i++){
        myFile >> letters[i].letter >>  letters[i].code;
    }

    string theCode;
    myFile >> theCode;

    myFile.close();

    cout << decypher (theCode, letters, numberOfLetters) << endl << endl;
}

int main() {
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2010\\TestFiles\\S2\\s2.1.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2010\\TestFiles\\S2\\s2.2.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2010\\TestFiles\\S2\\s2.2_original.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2010\\TestFiles\\S2\\s2.3.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2010\\TestFiles\\S2\\s2.4.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2010\\TestFiles\\S2\\s2.5.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2010\\TestFiles\\S2\\s2.6.in");

    return 0;
}

string decypher (string theCode, Letter letters [], int numberOfLetters){
    // sortList (&letters [0], int numberOfLetters);
    return "hiiiii";
}

/*
void sortList (Letter *letters, int numberOfLetters){
    Letter newList [numberOfLetters];
    int newIndex [numberOfLetters];
    int valueHolder = letters -> code.size();

    for (int i = 0; i < numberOfLetters; i++){
        if (letters + i -> code.size() > )
        for (int j = 0; j < numberOfLetters; j++){

        }
    }
}
*/

