#include <iostream>
#include <fstream>
#include <map>
#include <cstdio>
#include <string>

using namespace std;

bool uniqueDigits (int input) {

    char buffer [256];
    sprintf(buffer, "%d", input);
    string number = string(buffer);
    map<char, int> digits;

    for (int i = 0; i < number.length(); i++) {
        if (digits.count(number[i]) > 0) return false;
        digits[number[i]] = 1;
    }
    return true;
}

void test (const string& fileName){
    ifstream myFile;
    myFile.open(fileName.c_str());

    int start;
    myFile >> start;

    start++;
    while (!uniqueDigits(start)) start++;
    cout << start << endl;

    myFile.close();
}

int main()
{
//    test("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013 ThirdTime\\TestFiles\\S1\\testFile.txt");
    test("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013 ThirdTime\\TestFiles\\S1\\s1.1.in");
    test("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013 ThirdTime\\TestFiles\\S1\\s1.2.in");
    test("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013 ThirdTime\\TestFiles\\S1\\s1.3.in");
    test("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013 ThirdTime\\TestFiles\\S1\\s1.4.in");
    test("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013 ThirdTime\\TestFiles\\S1\\s1.5.in");
    test("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013 ThirdTime\\TestFiles\\S1\\s1.6.in");
    test("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013 ThirdTime\\TestFiles\\S1\\s1.7.in");
    test("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013 ThirdTime\\TestFiles\\S1\\s1.8.in");
    test("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013 ThirdTime\\TestFiles\\S1\\s1.9.in");
    test("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013 ThirdTime\\TestFiles\\S1\\s1.10.in");
    test("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013 ThirdTime\\TestFiles\\S1\\s1.11.in");
    test("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013 ThirdTime\\TestFiles\\S1\\s1.12.in");
    test("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013 ThirdTime\\TestFiles\\S1\\s1.13.in");
    test("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013 ThirdTime\\TestFiles\\S1\\s1.14.in");
    test("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013 ThirdTime\\TestFiles\\S1\\s1.15.in");

    return 0;
}
