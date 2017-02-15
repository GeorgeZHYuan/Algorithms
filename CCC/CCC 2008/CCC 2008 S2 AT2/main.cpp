#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

void test (const string& fileName) {
    ifstream myFile;
    myFile.open(fileName.c_str());
    while (true){
        int radius;
        myFile >> radius;
        if (radius == 0) break;
        int total = 0;
        for (int x = 1; x <= radius; x++) total += floor(sqrt(radius*radius - x*x))+ 1;
        cout << 4*total + 1 << endl;
    }cout << endl;
}

int main()
{
//    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2008\\TestFiles\\s2\\SelfTest.txt");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2008\\TestFiles\\s2\\s2.1.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2008\\TestFiles\\s2\\s2.2.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2008\\TestFiles\\s2\\s2.3.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2008\\TestFiles\\s2\\s2.4.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2008\\TestFiles\\s2\\s2.5.in");
    return 0;
}
