#include <iostream>
#include <fstream>

using namespace std;

void test (const string& fileName){
    ifstream myFile;
    myFile.open(fileName.c_str());

    myFile.close();
}

int main()
{
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2011\\TestFiles\\s5\\s5.1.in");
    return 0;
}
