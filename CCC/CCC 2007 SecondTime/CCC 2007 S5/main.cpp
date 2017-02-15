#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int maxScore (vector<int>& pins; int numberOfBalls; int BallWidth){
    return 0;
}

void test (const string& fileName){
    ifstream myFile;
    myFile.open(fileName.c_str());

    int testCases;
    myFile >> testCases;

for (int rep = 0; rep < testCases; rep++){

    int numberOfPins, numberOfBalls, ballWidth;
    vector<int> pins;
    myFile >> numberOfPins >> numberOfBalls >> ballWidth;
    int intValueHolder;
    for (int i = 0; i < numberOfPins; i++) {
        myFile >> intValueHolder;
        pins.push_back(intValueHolder);
    }

    cout << maxScore (pins, numberOfBalls, ballWidth) << end;
}
    myFile.close();
}

int main()
{
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2007 SecondTime\\TestFiles\\s5\\testFile.txt");
//    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2007 SecondTime\\TestFiles\\s5\\s5.1.in");
//    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2007 SecondTime\\TestFiles\\s5\\s5.2.in");
//    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2007 SecondTime\\TestFiles\\s5\\s5.3.in");
//    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2007 SecondTime\\TestFiles\\s5\\s5.4.in");
//    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2007 SecondTime\\TestFiles\\s5\\s5.5.in");
    return 0;
}
