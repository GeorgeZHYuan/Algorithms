#include <iostream>
#include <fstream>
#include <map>
#include <queue>

using namespace std;

struct ComparePairMax {
    bool operator () (pair<int,int>& a, pair<int, int>& b){
        if (a.second == b.second) return a.first < b.first;
        else return a.second < b.second;
    }
};
struct ComparePairMin {
    bool operator () (pair<int,int>& a, pair<int, int>& b){
        if (a.second == b.second) return a.first > b.first;
        else return a.second < b.second;
    }
};

void test(const string& fileName) {
    ifstream myFile;
    myFile.open(fileName.c_str());
    int detectedNumber, temp;
    myFile >> detectedNumber;

    map<int, int> readings;
    for (int i = 0; i < detectedNumber; i++) {
        myFile >> temp;
        if (readings.count(temp) > 0) readings[temp]++;
        else readings[temp] = 1;
    }

    priority_queue<pair<int, int>, vector<pair<int, int> >, ComparePairMax> maxList;
    for (map<int, int>::iterator it = readings.begin(); it != readings.end(); it++){
        maxList.push(pair<int, int>(it->first, it->second));
    }

    pair<int, int> maxTop (maxList.top());
    maxList.pop();

    if (maxList.top().second == maxTop.second) {
        priority_queue<pair<int, int>, vector<pair<int, int> >, ComparePairMin> minList;
        while (!maxList.empty()) {
            minList.push(maxList.top());
            maxList.pop();
        }
        int result = maxTop.first - minList.top().first;
        cout << max (result, -result) << endl;
    }
    else {
        vector<int> nextCanidiates;
        int nextBiggestSize = maxList.top().second;
        while (!maxList.empty()) {
            if (maxList.top().second != nextBiggestSize) break;
            nextCanidiates.push_back(maxList.top().first);
            maxList.pop();
        }
        int result = -1;
        for (int i = 0; i < nextCanidiates.size(); i++){
            int tempResult = maxTop.first - nextCanidiates[i];
            tempResult = max (-tempResult, tempResult);
            result = max (tempResult, result);
        }
        cout << result << endl;
    }

    myFile.close();
}

int main()
{
//    test("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2012 SecondTime\\TestFiles\\S3\\testFile.txt");
    test("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2012 SecondTime\\TestFiles\\S3\\s3.1.in");
    test("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2012 SecondTime\\TestFiles\\S3\\s3.2.in");
    test("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2012 SecondTime\\TestFiles\\S3\\s3.3.in");
    test("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2012 SecondTime\\TestFiles\\S3\\s3.4.in");
    test("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2012 SecondTime\\TestFiles\\S3\\s3.5.in");
    return 0;
}
