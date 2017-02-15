#include <iostream>
#include <fstream>

using namespace std;

void test (const string& fileName){
    ifstream myFile;
    myFile.open(fileName.c_str());
    int numberOfPeople;
    myFile >> numberOfPeople;
    numberOfPeople--;
    cout << (numberOfPeople*(numberOfPeople-1)*(numberOfPeople-2))/6 << endl;

    myFile.close();
}

int main()
{
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2012\\TestFiles\\S1\\s1.1.in");

    return 0;
}
