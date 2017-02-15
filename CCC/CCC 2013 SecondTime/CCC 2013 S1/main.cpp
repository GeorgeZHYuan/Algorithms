#include <iostream>
#include <string>
#include <fstream>
#include <set>
#include <cstdio>

using namespace std;

void test (const string& fileName) {
    ifstream myFile;
    myFile.open(fileName.c_str());

    set <char> digits;
    int number;

    myFile >> number;
    myFile.close();

    bool stop = false;
    while (!stop) {
        digits.clear();
        number++;
        char buffer [256];
        sprintf(buffer, "%d", number);
        string valueHolder (buffer);

        int oldSize = digits.size();
        for (int i = 0; i < valueHolder.length(); i++) {
            digits.insert(valueHolder[i]);
            if (oldSize == digits.size()) break;
            else {
                if (i == valueHolder.length() - 1) {
                    stop = true;
                    break;
                }
                oldSize = digits.size();
            }
        }
    }
    cout << number << endl;
}

int main()
{
//    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013 SecondTime\\TestFiles\\S1\\test.txt");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013 SecondTime\\TestFiles\\S1\\s1.1.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013 SecondTime\\TestFiles\\S1\\s1.2.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013 SecondTime\\TestFiles\\S1\\s1.3.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013 SecondTime\\TestFiles\\S1\\s1.4.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013 SecondTime\\TestFiles\\S1\\s1.5.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013 SecondTime\\TestFiles\\S1\\s1.6.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013 SecondTime\\TestFiles\\S1\\s1.7.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013 SecondTime\\TestFiles\\S1\\s1.8.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013 SecondTime\\TestFiles\\S1\\s1.9.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013 SecondTime\\TestFiles\\S1\\s1.10.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013 SecondTime\\TestFiles\\S1\\s1.11.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013 SecondTime\\TestFiles\\S1\\s1.12.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013 SecondTime\\TestFiles\\S1\\s1.13.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013 SecondTime\\TestFiles\\S1\\s1.14.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013 SecondTime\\TestFiles\\S1\\s1.15.in");

    return 0;
}
