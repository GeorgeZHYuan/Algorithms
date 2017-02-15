#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void test (const string& fileName){
    ifstream myFile;
    myFile.open(fileName.c_str());
    int endPoint;
    myFile >> endPoint;
    vector<int> points [10000];
    int a, b;
    while (true){
        myFile >> a >> b;
        if (a== 0 && b==0) break;
        points[max(a,b)].push_back(min(a,b));
    }

    int numberOfPaths = 0;
    vector<int> scanList;
    vector<int> nextList;
    scanList.push_back(endPoint);
    while (!scanList.empty()){
        for (int i = 0; i < scanList.size(); i++){
            if (scanList[i] == 1) {
                numberOfPaths++;
                continue;
            }
            for (int j = 0; j < points[scanList[i]].size(); j++){
                nextList.push_back(points[scanList[i]][j]);
            }
        }
        scanList = nextList;
        nextList.clear();
    }

    cout << numberOfPaths << endl;
    myFile.close();
}

void test1 (const string& fileName){
    ifstream myFile;
    myFile.open(fileName.c_str());
    int endPoint;
    myFile >> endPoint;
    vector<int> points [10000];
    int pointValue [10000];
    for (int i = 0; i < 10000; i++) pointValue[i] = 0;
    pointValue[1] = 1;

    int a, b;
    while (true){
        myFile >> a >> b;
        if (a==0 && b==0) break;
        points[max(a,b)].push_back(min(a,b));
    }

    if (endPoint != 1){
        for (int i = 2; i <= endPoint; i++){
            for (int j = 0; j < points[i].size(); j++){
                pointValue[i] += pointValue[points[i][j]];
            }
        }
    }

    cout << pointValue[endPoint] << endl;
    myFile.close();
}

int main()
{
//    test1 ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2007 SecondTime\\TestFiles\\s4\\testCase.txt");
    test1 ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2007 SecondTime\\TestFiles\\s4\\s4.1.in");
    test1 ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2007 SecondTime\\TestFiles\\s4\\s4.2.in");
    test1 ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2007 SecondTime\\TestFiles\\s4\\s4.3.in");
    test1 ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2007 SecondTime\\TestFiles\\s4\\s4.4.in");
    test1 ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2007 SecondTime\\TestFiles\\s4\\s4.5.in");

    return 0;
}
