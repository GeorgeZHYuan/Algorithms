#include <iostream>
#include <fstream>
#include <map>

using namespace std;

void test (const string& fileName){
    ifstream myFile;
    myFile.open(fileName.c_str());
    map <string, string> formations;
    int numberOfStudents;
    myFile >> numberOfStudents;
    string names [numberOfStudents];
    string partners [numberOfStudents];
    for (int i = 0; i < numberOfStudents; i++){
        myFile >> names[i];
    }
    for (int i = 0; i < numberOfStudents; i++){
        myFile >> partners[i];
    }
    myFile.close();
    for (int i = 0; i < numberOfStudents; i++){
        formations.insert(pair<string,string>(names[i],partners[i]));
    }
    int passed = true;
    for (map<string,string>::iterator it = formations.begin(); it != formations.end(); it++){
        if (it->second == it->first || it->first != formations[it->second]){
            passed = false;
            break;
        }
    }
    if (passed){
        cout << "good" << endl;
    }
    else {
        cout << "bad" << endl;
    }
}

int main() {
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2014\\Test Files\\s2\\s2.1a.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2014\\Test Files\\s2\\s2.1b.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2014\\Test Files\\s2\\s2.2a.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2014\\Test Files\\s2\\s2.2b.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2014\\Test Files\\s2\\s2.3a.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2014\\Test Files\\s2\\s2.3b.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2014\\Test Files\\s2\\s2.4a.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2014\\Test Files\\s2\\s2.4b.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2014\\Test Files\\s2\\s2.5a.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2014\\Test Files\\s2\\s2.5b.in");
    return 0;
}
