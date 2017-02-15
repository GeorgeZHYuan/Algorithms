#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <set>

using namespace std;

struct ListItem {
    int columnNumber;
    int rowNumber;
    int totalDistance = 0;
    char currentBlock;

    ListItem (int a, int b, int c, char d){
        columnNumber = a;
        rowNumber = b;
        totalDistance = c;
        currentBlock = d;
    }
    void setValue (int a, int b, int c, char d){
        columnNumber = a;
        rowNumber = b;
        totalDistance = c;
        currentBlock = d;
    }
};

void test (const string& fileName){
    ifstream myFile;
    myFile.open(fileName.c_str());

    int testRuns;
    myFile >> testRuns;

    for (int q = 0; q < testRuns; q++){
        int rowLength, columnLength;
        myFile >> columnLength >> rowLength;
        char theMap [columnLength] [rowLength];

        for (int y = 0; y < columnLength; y++){
            for (int x = 0; x < rowLength; x++){
                myFile >> theMap [y][x];
            }
        }

        vector<ListItem> oldList;
        ListItem valueHolder (0, 0, 1, theMap[0][0]);
        oldList.push_back(valueHolder);

        vector<ListItem> newList = oldList;
        set<int> outList;
        outList.insert(0);

        bool done = false;
        while (!done){
            if (oldList.empty()){
                cout << "-1" << endl;
                break;
            }
            else {
                for (int i = 0; i < oldList.size(); i++){
                    if (theMap[oldList[i].columnNumber][oldList[i].rowNumber] != '*') {
                        if (oldList[i].columnNumber == columnLength-1 && oldList[i].rowNumber == rowLength-1) {
                            cout << oldList[i].totalDistance << endl;
                            done = true;
                            break;
                        }
                        if (theMap[oldList[i].columnNumber][oldList[i].rowNumber] == '+') {
                            if (oldList[i].columnNumber+1 < columnLength &&
                                outList.find((oldList[i].columnNumber+1)*columnLength+oldList[i].rowNumber) == outList.end()){
                                valueHolder.setValue (oldList[i].columnNumber+1, oldList[i].rowNumber, oldList[i].totalDistance+1,
                                                      theMap[oldList[i].columnNumber+1] [oldList[i].rowNumber]);
                                newList.push_back(valueHolder);
                                outList.insert((oldList[i].columnNumber+1)*columnLength+oldList[i].rowNumber);
                            }
                            if (oldList[i].rowNumber+1 < rowLength &&
                                outList.find((oldList[i].columnNumber)*columnLength+oldList[i].rowNumber+1) == outList.end()){
                                valueHolder.setValue (oldList[i].columnNumber, oldList[i].rowNumber+1, oldList[i].totalDistance+1,
                                                      theMap[oldList[i].columnNumber] [oldList[i].rowNumber+1]);
                                newList.push_back(valueHolder);
                                outList.insert((oldList[i].columnNumber)*columnLength+oldList[i].rowNumber+1);
                            }
                            if (oldList[i].columnNumber-1 >= 0 &&
                                outList.find((oldList[i].columnNumber-1)*columnLength+oldList[i].rowNumber) == outList.end()){
                                valueHolder.setValue (oldList[i].columnNumber-1, oldList[i].rowNumber, oldList[i].totalDistance+1,
                                                      theMap[oldList[i].columnNumber-1] [oldList[i].rowNumber]);
                                newList.push_back(valueHolder);
                                outList.insert((oldList[i].columnNumber-1)*columnLength+oldList[i].rowNumber);
                            }
                            if (oldList[i].rowNumber-1 >= 0 &&
                                outList.find((oldList[i].columnNumber)*columnLength+oldList[i].rowNumber-1) == outList.end()){
                                valueHolder.setValue (oldList[i].columnNumber, oldList[i].rowNumber-1, oldList[i].totalDistance+1,
                                                      theMap[oldList[i].columnNumber] [oldList[i].rowNumber-1]);
                                newList.push_back(valueHolder);
                                outList.insert((oldList[i].columnNumber)*columnLength+oldList[i].rowNumber-1);
                            }
                        }
                        else if (theMap[oldList[i].columnNumber][oldList[i].rowNumber] == '|'){
                            if (oldList[i].columnNumber+1 < columnLength &&
                                outList.find((oldList[i].columnNumber+1)*columnLength+oldList[i].rowNumber) == outList.end()){
                                valueHolder.setValue (oldList[i].columnNumber+1, oldList[i].rowNumber, oldList[i].totalDistance+1,
                                                      theMap[oldList[i].columnNumber+1] [oldList[i].rowNumber]);
                                newList.push_back(valueHolder);
                                outList.insert((oldList[i].columnNumber+1)*columnLength+oldList[i].rowNumber);

                            }
                            if (oldList[i].columnNumber-1 >= 0 &&
                                outList.find((oldList[i].columnNumber-1)*columnLength+oldList[i].rowNumber) == outList.end()){
                                valueHolder.setValue (oldList[i].columnNumber-1, oldList[i].rowNumber, oldList[i].totalDistance+1,
                                                      theMap[oldList[i].columnNumber-1] [oldList[i].rowNumber]);
                                newList.push_back(valueHolder);
                                outList.insert((oldList[i].columnNumber-1)*columnLength+oldList[i].rowNumber);
                            }
                        }
                        else if (theMap[oldList[i].columnNumber][oldList[i].rowNumber] == '-'){
                            if (oldList[i].rowNumber+1 < rowLength &&
                                outList.find((oldList[i].columnNumber)*columnLength+oldList[i].rowNumber+1) == outList.end()){
                                valueHolder.setValue (oldList[i].columnNumber, oldList[i].rowNumber+1, oldList[i].totalDistance+1,
                                                      theMap[oldList[i].columnNumber] [oldList[i].rowNumber+1]);
                                newList.push_back(valueHolder);
                                outList.insert((oldList[i].columnNumber)*columnLength+oldList[i].rowNumber+1);
                            }
                            if (oldList[i].rowNumber-1 >= 0 &&
                                outList.find((oldList[i].columnNumber)*columnLength+oldList[i].rowNumber-1) == outList.end()){
                                valueHolder.setValue (oldList[i].columnNumber, oldList[i].rowNumber-1, oldList[i].totalDistance+1,
                                                      theMap[oldList[i].columnNumber] [oldList[i].rowNumber-1]);
                                newList.push_back(valueHolder);
                                outList.insert((oldList[i].columnNumber)*columnLength+oldList[i].rowNumber-1);
                            }
                        }
                    }
                }
                oldList = newList;
                newList.clear();
            }
        }
    }
    cout << endl;
    myFile.close();
}

int main()
{
//    test("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2008\\TestFiles\\s1\\SelfTest.txt");
    test("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2008\\TestFiles\\s3\\s3.1.in");
    test("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2008\\TestFiles\\s3\\s3.2.in");
    test("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2008\\TestFiles\\s3\\s3.3.in");
    test("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2008\\TestFiles\\s3\\s3.4.in");
    test("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2008\\TestFiles\\s3\\s3.5.in");

    return 0;
}
