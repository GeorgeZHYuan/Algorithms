#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <string>

using namespace std;

string matchedProperly (map<string,string>& matches, vector<string>& names){
    for (int i = 0; i < names.size(); i++){
        if (matches[names[i]] == names[i]) return "bad";
        else if (matches[matches[names[i]]] != names[i]) return "bad";
    }
    return "good";
}

void test (const string& fileName) {
    ifstream myFile;
    myFile.open(fileName.c_str());

    int numberOfPeople;
    myFile >> numberOfPeople;
    vector<string> names;
    map<string, string> matches;

    string temp;
    for (int i = 0; i < numberOfPeople; i++){
        myFile >> temp;
        names.push_back(temp);
    }
    for (int i = 0; i < numberOfPeople; i++){
        myFile >> temp;
        matches[names[i]] = temp;
    }

    cout << matchedProperly(matches, names) << endl;
    myFile.close();
}

int main()
{
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2014 SecondTime\\TestFiles\\s2\\testFile.txt");
//    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2014 SecondTime\\TestFiles\\s2\\s2.1a.in");
//    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2014 SecondTime\\TestFiles\\s2\\s2.1b.in");
//    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2014 SecondTime\\TestFiles\\s2\\s2.2a.in");
//    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2014 SecondTime\\TestFiles\\s2\\s2.2b.in");
//    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2014 SecondTime\\TestFiles\\s2\\s2.3a.in");
//    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2014 SecondTime\\TestFiles\\s2\\s2.3b.in");
//    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2014 SecondTime\\TestFiles\\s2\\s2.4a.in");
//    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2014 SecondTime\\TestFiles\\s2\\s2.4b.in");
//    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2014 SecondTime\\TestFiles\\s2\\s2.5a.in");
//    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2014 SecondTime\\TestFiles\\s2\\s2.5b.in");

    return 0;
}
