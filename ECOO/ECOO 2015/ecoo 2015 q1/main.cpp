#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

void test (const string& fileName){
    ifstream myFile;
    myFile.open(fileName.c_str());
    for (int testCases = 0; testCases < 10; testCases++){
        double smarties [8];
        for (int i = 0; i < 8; i++) smarties [i] = 0;
        string temp;
        while  (!myFile.eof()){
            myFile >> temp;
            if (temp == "orange") smarties[0]++;
            else if (temp == "blue") smarties[1]++;
            else if (temp == "green") smarties[2]++;
            else if (temp == "yellow") smarties[3]++;
            else if (temp == "pink") smarties[4]++;
            else if (temp == "violet") smarties[5]++;
            else if (temp == "brown") smarties[6]++;
            else if (temp == "red") smarties[7]++;
            else break;
        }
        for (int i = 0; i < 3; i++) myFile >> temp;
        double totalTime = 0;
        for (int i = 0; i < 7; i++) totalTime += ceil(smarties[i]/7)*13;
        totalTime += smarties[7]*16;
        cout << totalTime << endl;

    }
    myFile.close();
}

int main()
{
    test ("C:\\Users\\ayuan\\Desktop\\ECOO 2015\\ecoo 2015 q1\\DATA12.txt");
//    test ("C:\\Users\\ayuan\\Desktop\\ECOO 2015\\ecoo 2015 q1\\DATA11.txt");
//    test ("C:\\Users\\ayuan\\Desktop\\ECOO 2015\\ecoo 2015 q1\\testFile.txt");

    return 0;
}
