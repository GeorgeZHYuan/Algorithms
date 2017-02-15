#include <iostream>
#include <fstream>

using namespace std;

void test (const string& fileName){
    ifstream myFile;
    myFile.open(fileName.c_str());
    string winner;
    int coldest = 201;

    string temps;
    int tempi;
    while(true){
        myFile >> temps >> tempi;
        if (tempi < coldest) {
                winner = temps;
                coldest = tempi;
        }
        if (temps == "Waterloo") break;
    }
    cout << winner << endl;
}

int main()
{

//    test("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2008\\TestFiles\\s1\\SelfTest.txt");
    test("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2008\\TestFiles\\s1\\s1.1.in");
    test("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2008\\TestFiles\\s1\\s2.1.in");
    test("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2008\\TestFiles\\s1\\s3.1.in");
    return 0;
}
