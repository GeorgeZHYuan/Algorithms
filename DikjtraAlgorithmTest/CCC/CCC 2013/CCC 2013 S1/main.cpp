#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <fstream>

using namespace std;

void test (const string& fileName) {
    ifstream myFile;
    myFile.open(fileName.c_str());
    int theInt;
    myFile >> theInt;
    myFile.close();
    bool distinct;
    string sub;
    while (true){
        theInt++;
        char buffer [256];
        sprintf(buffer, "%d", theInt);
        string sub = string(buffer);
        if (sub.size() == 1) break;
        for (int i = 0; i < sub.size()-1; i++){
            distinct = true;
            for (int j = i+1; j < sub.size(); j++){
                if (sub[j] == sub[i]){
                    distinct = false;
                    break;
                }
            }
            if (!distinct) break;
        }
        if (distinct) break;
    }
    cout << theInt << endl;
}

int main() {

    test("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013\\TestFiles\\S1\\s1.1.in");
    test("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013\\TestFiles\\S1\\s1.2.in");
    test("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013\\TestFiles\\S1\\s1.3.in");
    test("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013\\TestFiles\\S1\\s1.4.in");
    test("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013\\TestFiles\\S1\\s1.5.in");
    test("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013\\TestFiles\\S1\\s1.6.in");
    test("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013\\TestFiles\\S1\\s1.7.in");
    test("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013\\TestFiles\\S1\\s1.8.in");
    test("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013\\TestFiles\\S1\\s1.9.in");
    test("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013\\TestFiles\\S1\\s1.10.in");
    test("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013\\TestFiles\\S1\\s1.11.in");
    test("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013\\TestFiles\\S1\\s1.12.in");
    test("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013\\TestFiles\\S1\\s1.13.in");
    test("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013\\TestFiles\\S1\\s1.14.in");
    test("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013\\TestFiles\\S1\\s1.15.in");

    return 0;
}
