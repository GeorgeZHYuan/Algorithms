#include <iostream>
#include <fstream>

using namespace std;

void test (const string& fileName) {
    ifstream myFile;
    myFile.open(fileName.c_str());

    int coldest = 1000;
    string town = "";

    int temp = 0;
    string name = "";

    while (true){
        myFile >> name >> temp;
        if (temp <= coldest) {
            coldest = temp;
            town = name;
        }
        if (name == "Waterloo") break;
    }
    cout << town << endl;
}

int main()
{
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2008\\TestFiles\\s1\\s1.1.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2008\\TestFiles\\s1\\s1.2.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2008\\TestFiles\\s1\\s1.3.in");
    return 0;
}
