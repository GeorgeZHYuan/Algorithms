#include <iostream>
#include <fstream>
#include <queue>
#include <string>

using namespace std;

class Computer {
public:
    string name;
    long value;

    void calculateValue (int r, int s, int d) {value = (2*r + 3*s + d);}
};

class CompareComputer {
public:
    bool operator()(Computer& first, Computer& second){
        if (first.value < second.value) return true;
        else if (first.value == second.value && first.name > second.name) return true;
        return false;
    }
};

void test (const string& fileName){
    ifstream myFile;
    myFile.open (fileName.c_str());

    int numberOfEntres;
    myFile >> numberOfEntres;
    if (numberOfEntres > 0){
        priority_queue<Computer, vector<Computer>, CompareComputer> theList;
        Computer valueHolder;

        for (int i = 0; i < numberOfEntres; i++){
            int r, s, d;
            myFile >> valueHolder.name >> r >> s >> d;
            valueHolder.calculateValue(r, s, d);
            theList.push(valueHolder);
        }
            valueHolder = theList.top();
            theList.pop();
            cout << valueHolder.name << endl;

            if (!theList.empty()){
                valueHolder = theList.top();
                cout << valueHolder.name << endl;
            }
    }
    cout << endl;

    myFile.close();
}

int main() {
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2010\\TestFiles\\S1\\s1.1.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2010\\TestFiles\\S1\\s1.2.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2010\\TestFiles\\S1\\s1.3.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2010\\TestFiles\\S1\\s1.4.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2010\\TestFiles\\S1\\s1.5.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2010\\TestFiles\\S1\\s1.6.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2010\\TestFiles\\S1\\s1.7.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2010\\TestFiles\\S1\\s1.8.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2010\\TestFiles\\S1\\s1.9.in");

    return 0;
}
