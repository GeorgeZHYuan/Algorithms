#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <stdlib.h>

using namespace std;

struct Signals {
    int signalStrength;
    int frequency;

    void setValue (int _signalStrength, int _frequency){
        signalStrength = _signalStrength;
        frequency = _frequency;
    }
};

struct CompareSignals {
    bool operator ()(const Signals& one, const Signals& two){
        return (one.frequency > two.frequency);
    }
};

void test (const string& fileName){
    ifstream myFile;
    myFile.open(fileName.c_str());
    int numberOfSensors;
    myFile >> numberOfSensors;

    set<int> outList;
    map<int, int> frequencies;

    for (int i = 0; i < numberOfSensors; i++){
        int signal;
        int oldSize = outList.size();
        myFile >> signal;
        outList.insert(signal);
        if (outList.size() != oldSize){
            frequencies.insert(pair<int, int>(signal, 1));
        }
        else {
            (*(frequencies.find(signal))).second++;
        }
    }
    myFile.close();
    vector<Signals> scanList;
    Signals valueHolder;
    for (map<int,int>::iterator it = frequencies.begin(); it != frequencies.end(); it++){
        valueHolder.setValue (it->first, it->second);
        scanList.push_back(valueHolder);
    }

    sort(scanList.begin(), scanList.end(), CompareSignals());

//for (int i = 0; i < 50; i++){
//    cout << scanList[i].signalStrength << " " << scanList[i].frequency << endl;
//}cout << endl;

    int lastFrequency = scanList[0].frequency;
    int placeHolder = 0;
    int maxi [2] = {0, 0};
    int mini [2] = {9999999, 9999999};

    for (int j = 0; j < 2; j++){
        for (int i = placeHolder; i < scanList.size(); i++){
            if (scanList[i].frequency != lastFrequency){
                lastFrequency = scanList[i].frequency;
                placeHolder = i;
                break;
            }
            else {
                maxi[j] = max(maxi[j], scanList[i].signalStrength);
                mini[j] = min(mini[j], scanList[i].signalStrength);
            }
        }
    }
//cout << "maxFirst and minSec: " << maxi[0] << " " << mini [1] << endl;
//cout << "minFirst and maxSec: " << mini[0] << " " << maxi [1]<< endl;
    cout << max(abs(maxi[0] - mini[1]), abs(mini[0] - maxi[1])) << endl;
}

int main()
{
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2012\\TestFiles\\S3\\s3.1.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2012\\TestFiles\\S3\\s3.2.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2012\\TestFiles\\S3\\s3.3.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2012\\TestFiles\\S3\\s3.4.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2012\\TestFiles\\S3\\s3.5.in");
    return 0;
}
