#include <iostream>
#include <fstream>

using namespace std;

void test (const string& fileName) {
    ifstream myFile;
    myFile.open(fileName.c_str());
    string input = "";
    int tCount = 0, sCount = 0, lines;

    myFile >> lines;

    for (int i = 0; i <= lines; i++){
        char temp [256];
        myFile.getline(temp, 256);
        input += temp;
    }
    for (int i = 0; i < input.length(); i++){
        if (input[i] == 's' || input[i] == 'S') sCount++;
        else if (input[i] == 't' || input[i] == 'T') tCount++;
    }

    if (tCount > sCount) cout << "English" << endl;
    else cout << "French" << endl;

    myFile.close();
}

int main()
{
//    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2011 SecondTime\\TestFiles\\s1\\testFile.txt");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2011 SecondTime\\TestFiles\\s1\\s1.1.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2011 SecondTime\\TestFiles\\s1\\s1.2.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2011 SecondTime\\TestFiles\\s1\\s1.3.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2011 SecondTime\\TestFiles\\s1\\s1.4.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2011 SecondTime\\TestFiles\\s1\\s1.5.in");
    return 0;
}
