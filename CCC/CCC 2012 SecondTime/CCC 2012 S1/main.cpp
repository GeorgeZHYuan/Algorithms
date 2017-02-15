#include <iostream>
#include <fstream>

using namespace std;

void test(const string& fileName) {
    ifstream myFile;
    myFile.open(fileName.c_str());
    int scorer;
    myFile >> scorer;
    if (scorer < 4) cout << 0 << endl;
    else cout << ((scorer-1)*(scorer-2)*(scorer-3))/6 << endl;

    myFile.close();
}

int main()
{
//    test("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2012 SecondTime\\TestFiles\\S1\\testFile.txt");
    test("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2012 SecondTime\\TestFiles\\S1\\s1.1.in");
    test("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2012 SecondTime\\TestFiles\\S1\\s1.2.in");
    test("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2012 SecondTime\\TestFiles\\S1\\s1.3.in");
    test("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2012 SecondTime\\TestFiles\\S1\\s1.4.in");
    test("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2012 SecondTime\\TestFiles\\S1\\s1.5.in");
    return 0;
}
