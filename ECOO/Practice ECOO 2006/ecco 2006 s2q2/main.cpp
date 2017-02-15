#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct Code {
    int numbers [3];
    Code returnValue (int one, int two, int three){
        Code spare;
        spare.numbers[0] = one;
        spare.numbers[1] = two;
        spare.numbers[2] = three;
        return spare;
    }
    bool theCodeIs (int one, int two, int three){
        if (numbers[0] == one && numbers[1] == two && numbers[2] == three) return true;
        return false;
    }
    void switchValues (Code& two, int number){
            int temp = numbers[number];
            numbers[number] = two.numbers[number];
            two.numbers[number] = temp;
    }
};

char returnChar (Code spare){
    if (spare.theCodeIs(0,0,0)) return ' ';
    else if (spare.theCodeIs(0,0,1)) return 'A';
    else if (spare.theCodeIs(0,0,2)) return 'B';
    else if (spare.theCodeIs(0,1,0)) return 'C';
    else if (spare.theCodeIs(0,1,1)) return 'D';
    else if (spare.theCodeIs(0,1,2)) return 'E';
    else if (spare.theCodeIs(0,2,0)) return 'F';
    else if (spare.theCodeIs(0,2,1)) return 'G';
    else if (spare.theCodeIs(0,2,2)) return 'H';
    else if (spare.theCodeIs(1,0,0)) return 'I';
    else if (spare.theCodeIs(1,0,1)) return 'J';
    else if (spare.theCodeIs(1,0,2)) return 'K';
    else if (spare.theCodeIs(1,1,0)) return 'L';
    else if (spare.theCodeIs(1,1,1)) return 'M';
    else if (spare.theCodeIs(1,1,2)) return 'N';
    else if (spare.theCodeIs(1,2,0)) return 'O';
    else if (spare.theCodeIs(1,2,1)) return 'P';
    else if (spare.theCodeIs(1,2,2)) return 'Q';
    else if (spare.theCodeIs(2,0,0)) return 'R';
    else if (spare.theCodeIs(2,0,1)) return 'S';
    else if (spare.theCodeIs(2,0,2)) return 'T';
    else if (spare.theCodeIs(2,1,0)) return 'U';
    else if (spare.theCodeIs(2,1,1)) return 'V';
    else if (spare.theCodeIs(2,1,2)) return 'W';
    else if (spare.theCodeIs(2,2,0)) return 'X';
    else if (spare.theCodeIs(2,2,1)) return 'Y';
    else if (spare.theCodeIs(2,2,2)) return 'Z';
}
Code returnCode (char theLetter){
    Code spare;
    if (theLetter == ' ') return spare.returnValue(0,0,0);
    else if (theLetter == 'A') return spare.returnValue(0,0,1);
    else if (theLetter == 'B') return spare.returnValue(0,0,2);
    else if (theLetter == 'C') return spare.returnValue(0,1,0);
    else if (theLetter == 'D') return spare.returnValue(0,1,1);
    else if (theLetter == 'E') return spare.returnValue(0,1,2);
    else if (theLetter == 'F') return spare.returnValue(0,2,0);
    else if (theLetter == 'G') return spare.returnValue(0,2,1);
    else if (theLetter == 'H') return spare.returnValue(0,2,2);
    else if (theLetter == 'I') return spare.returnValue(1,0,0);
    else if (theLetter == 'J') return spare.returnValue(1,0,1);
    else if (theLetter == 'K') return spare.returnValue(1,0,2);
    else if (theLetter == 'L') return spare.returnValue(1,1,0);
    else if (theLetter == 'M') return spare.returnValue(1,1,1);
    else if (theLetter == 'N') return spare.returnValue(1,1,2);
    else if (theLetter == 'O') return spare.returnValue(1,2,0);
    else if (theLetter == 'P') return spare.returnValue(1,2,1);
    else if (theLetter == 'Q') return spare.returnValue(1,2,2);
    else if (theLetter == 'R') return spare.returnValue(2,0,0);
    else if (theLetter == 'S') return spare.returnValue(2,0,1);
    else if (theLetter == 'T') return spare.returnValue(2,0,2);
    else if (theLetter == 'U') return spare.returnValue(2,1,0);
    else if (theLetter == 'V') return spare.returnValue(2,1,1);
    else if (theLetter == 'W') return spare.returnValue(2,1,2);
    else if (theLetter == 'X') return spare.returnValue(2,2,0);
    else if (theLetter == 'Y') return spare.returnValue(2,2,1);
    else if (theLetter == 'Z') return spare.returnValue(2,2,2);
}

void test (const string& fileName){
    ifstream myFile;
    myFile.open(fileName.c_str());

    for (int tests = 1; tests < 3; tests++){
        char theLine [256];
        myFile.getline(theLine,256);

        string theInput = theLine;
        vector <Code> codes;
        for (int i = 0; i < theInput.size(); i++) codes.push_back(returnCode(theInput[i]));

        for (int i = 1; i < codes.size(); i+=2) {
            codes[i].switchValues (codes[i-1], 0);
            if (i != theInput.size()-1) codes[i].switchValues (codes[i+1], 2);
            else codes[i].switchValues (codes[0], 2);
        }
        for (int i = 0; i < codes.size(); i++) cout << returnChar(codes[i]);
        cout << endl;
    }
    myFile.close();
}

int main()
{
    test ("C:\\Users\\ayuan\\Desktop\\ECOO 2006\\ecco 2006 s2q2\\testFile.txt");
    return 0;
}
