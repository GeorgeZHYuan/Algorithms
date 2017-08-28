#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

void test (const string& fileName) {
    ifstream myFile;
    myFile.open(fileName.c_str());
    for (int testCases = 0; testCases < 10; testCases++){
        float candyList [8] = {0, 0, 0, 0, 0, 0 ,0 ,0};
        while (true){
            string input;
            myFile >> input;
            if (input == "orange") candyList [0]++;
            else if (input == "blue") candyList [1]++;
            else if (input == "green") candyList [2]++;
            else if (input == "yellow") candyList [3]++;
            else if (input == "pink") candyList [4]++;
            else if (input == "violet") candyList [5]++;
            else if (input == "brown") candyList [6]++;
            else if (input == "red") candyList [7]++;
            else if (input == "end") {
                myFile >> input >> input;
                break;
            }
        }
        int totalTime = 0;
        for (int i = 0; i < 7; i++){
            totalTime += ceil(candyList[i]/7)*13;
        }
        totalTime += candyList[7]*16;
        cout << totalTime << endl;
    }
}

int main()
{
//    test ("C:\\Users\\ayuan\\Documents\\Computer\\ECOOCS_2015\\ECOO 2015 Round 1\\testCase.txt");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\ECOOCS_2015\\ECOO 2015 Round 1\\Round 1 Data\\DATA11.txt");

    return 0;
}
