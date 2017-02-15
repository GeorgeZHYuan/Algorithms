#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>

using namespace std;

struct Node {
    vector<int> shorterPPL;
};

bool breadthFirstSearch (int p1, int p2, vector<Node>& personList) {
    vector<int> scanList;
    vector<int> nextList;
    map<int, bool> scanned;

    scanList.push_back(p1);
    scanned[p1] = true;

    while (!scanList.empty()){
        for (int i = 0; i < scanList.size(); i++){
            for (int j = 0; j < personList[scanList[i]].shorterPPL.size(); j++){
                if (!scanned[personList[scanList[i]].shorterPPL[j]]){
                    scanned[personList[scanList[i]].shorterPPL[j]] = true;
                    if (personList[scanList[i]].shorterPPL[j] == p2) return true;
                    nextList.push_back(personList[scanList[i]].shorterPPL[j]);
                }
            }
        }
        scanList = nextList;
        nextList.clear();
    }
    return false;
}

void test (const string& fileName) {
    ifstream myFile;
    myFile.open(fileName.c_str());
    vector<Node> personList;

    int people = 0;
    int comparisions = 0;
    myFile >> people >> comparisions;

    Node valueHolder;
    for (int i = 0; i < people; i++) personList.push_back(valueHolder);

    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < comparisions; i++){
        myFile >> p1 >> p2;
        p1--;p2--;
        personList[p1].shorterPPL.push_back(p2);
    }

    myFile >> p1 >> p2;
    p1--;p2--;
    if (p1 == p2 || breadthFirstSearch(p2, p1, personList)) cout << "no" << endl;
    else if (breadthFirstSearch(p1, p2, personList)) cout << "yes" << endl;
    else cout << "unknown" << endl;
}

int main()
{
//    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013 SecondTime\\TestFiles\\S4\\TestCase1.txt");
//    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013 SecondTime\\TestFiles\\S4\\TestCase2.txt");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013 SecondTime\\TestFiles\\S4\\s4.1-1.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013 SecondTime\\TestFiles\\S4\\s4.1-2.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013 SecondTime\\TestFiles\\S4\\s4.1-3.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013 SecondTime\\TestFiles\\S4\\s4.1-4.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013 SecondTime\\TestFiles\\S4\\s4.1-5.in"); cout << endl;
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013 SecondTime\\TestFiles\\S4\\s4.2-1.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013 SecondTime\\TestFiles\\S4\\s4.2-2.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013 SecondTime\\TestFiles\\S4\\s4.2-3.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013 SecondTime\\TestFiles\\S4\\s4.2-4.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013 SecondTime\\TestFiles\\S4\\s4.2-5.in"); cout << endl;
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013 SecondTime\\TestFiles\\S4\\s4.3-1.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013 SecondTime\\TestFiles\\S4\\s4.3-2.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013 SecondTime\\TestFiles\\S4\\s4.3-3.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013 SecondTime\\TestFiles\\S4\\s4.3-4.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013 SecondTime\\TestFiles\\S4\\s4.3-5.in"); cout << endl;
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013 SecondTime\\TestFiles\\S4\\s4.4-1.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013 SecondTime\\TestFiles\\S4\\s4.4-2.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013 SecondTime\\TestFiles\\S4\\s4.4-3.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013 SecondTime\\TestFiles\\S4\\s4.4-4.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013 SecondTime\\TestFiles\\S4\\s4.4-5.in"); cout << endl;
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013 SecondTime\\TestFiles\\S4\\s4.5-1.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013 SecondTime\\TestFiles\\S4\\s4.5-2.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013 SecondTime\\TestFiles\\S4\\s4.5-3.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013 SecondTime\\TestFiles\\S4\\s4.5-4.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013 SecondTime\\TestFiles\\S4\\s4.5-5.in"); cout << endl;
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013 SecondTime\\TestFiles\\S4\\s4.6-1.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013 SecondTime\\TestFiles\\S4\\s4.6-2.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013 SecondTime\\TestFiles\\S4\\s4.6-3.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013 SecondTime\\TestFiles\\S4\\s4.6-4.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013 SecondTime\\TestFiles\\S4\\s4.6-5.in");

    return 0;
}
