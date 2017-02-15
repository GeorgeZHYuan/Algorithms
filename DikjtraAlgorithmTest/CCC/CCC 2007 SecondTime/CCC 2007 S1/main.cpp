#include <iostream>
#include <fstream>

using namespace std;

string ofAge (int year, int month, int day){
    if (year > 1989) return "No";
    if (year == 1989) {
        if (month > 2) return "No";
        if (month == 2) {
            if (day <= 27) return "Yes";
            return "No";
        }
        return "Yes";
    }
    return "Yes";
}

void test (const string& fileName) {
    ifstream myFile;
    myFile.open(fileName.c_str());
//
    int testCases;
    myFile >> testCases;
    int y, m, d;
    for (int i = 0; i < testCases; i++){
        myFile >> y >> m >> d;
        cout << ofAge(y, m, d) << endl;
    } cout << endl;

    myFile.close();
}

int main()
{
//    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2007 SecondTime\\TestFiles\\s1\\testFile.txt");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2007 SecondTime\\TestFiles\\s1\\s1.1.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2007 SecondTime\\TestFiles\\s1\\s1.2.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2007 SecondTime\\TestFiles\\s1\\s1.3.in");

    return 0;
}
