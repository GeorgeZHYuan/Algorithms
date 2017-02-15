#include <iostream>
#include <fstream>

using namespace std;

int value (char input) {
    if (input == 'I') return 1;
    else if (input == 'V') return 5;
    else if (input == 'X') return 10;
    else if (input == 'L') return 50;
    else if (input == 'C') return 100;
    else if (input == 'D') return 500;
    else if (input == 'M') return 1000;
    else return input - '0';
}

void test(const string& fileName) {
    ifstream myFile;
    myFile.open(fileName.c_str());
    string input;
    myFile >> input;

    int inputValue = 0;
    if (input.length() > 2){
        for (int i = 0; i < input.length()-2; i+=2){
            if (value(input[i+3]) > value(input[i+1])) inputValue -= value(input[i]) * value(input[i+1]);
            else inputValue += value(input[i]) * value(input[i+1]);
        }
        inputValue += value(input[input.length()-2]) * value(input[input.length()-1]);
    }
    else inputValue = value(input[0]) * value(input[1]);
    cout << inputValue << endl;

    myFile.close();
}

int main()
{
//    test("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2012 SecondTime\\TestFiles\\S2\\testFile.txt");
    test("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2012 SecondTime\\TestFiles\\S2\\s2.1.in");
    test("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2012 SecondTime\\TestFiles\\S2\\s2.2.in");
    test("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2012 SecondTime\\TestFiles\\S2\\s2.3.in");
    test("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2012 SecondTime\\TestFiles\\S2\\s2.4.in");
    test("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2012 SecondTime\\TestFiles\\S2\\s2.5.in");
    return 0;
}
