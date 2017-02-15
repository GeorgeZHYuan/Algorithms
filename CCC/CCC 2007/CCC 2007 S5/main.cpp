// slow version (about 25seconds total run time)

#include <iostream>
#include <fstream>
#include <vector>


using namespace std;

int maximumPossibleScore (int pins [], int numberOfPins, int numberOfBowlingBalls, int bowlingBallWidth) {
    int sumList [numberOfPins];
    vector<int> oldList;
    for (int i = 0; i < numberOfPins; i++){
        oldList.push_back(0);
    }
    vector<int> newList;


    for (int i = 0; i < numberOfPins; i++){
    sumList[i] = 0;
        for (int j = i; j >= i-bowlingBallWidth+1 && j >= 0; j--){
            sumList[i] += pins[j];
        }
    }

    for (int i = 1; i <= numberOfBowlingBalls; i++){
            for (int j = 0; j < numberOfPins; j++){
                if (i*bowlingBallWidth >= j+1){
                    int amount = 0;
                    for (int k = j; k >= 0; k--){
                        amount += pins[k];
                    }
                    newList.push_back(amount);
                }
                else {
                    if (sumList[j]+oldList[j-bowlingBallWidth] > newList[j-1]){
                        newList.push_back(sumList[j]+oldList[j-bowlingBallWidth]);
                    }
                    else {
                        newList.push_back(newList[j-1]);
                    }
                }
            }

        oldList.clear();
        oldList = newList;
        newList.clear();
    }

    return oldList[numberOfPins-1];
}

void test (const string& fileName){
    ifstream myFile;
    myFile.open(fileName.c_str());

    int numberOfTrials;
    myFile >> numberOfTrials;

    int answers [numberOfTrials];

    for (int i = 0; i < numberOfTrials; i++){
        int numberOfPins, numberOfBowlingBalls, bowlingBallWidth;
        myFile >> numberOfPins >> numberOfBowlingBalls >> bowlingBallWidth;
        int pins [numberOfPins];

        for (int j = 0; j < numberOfPins; j++){
            int score;
            myFile >> score;
            pins[j] = score;
        }
        answers[i] = maximumPossibleScore (pins, numberOfPins, numberOfBowlingBalls, bowlingBallWidth);
    }

    for (int i = 0; i < numberOfTrials; i++){
        cout << answers[i] << endl;
    } cout << endl;

    myFile.close();
}

int main() {
//    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2007\\TestFiles\\s5\\test.txt");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2007\\TestFiles\\s5\\s5.1.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2007\\TestFiles\\s5\\s5.2.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2007\\TestFiles\\s5\\s5.3.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2007\\TestFiles\\s5\\s5.4.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2007\\TestFiles\\s5\\s5.5.in");

    return 0;
}
