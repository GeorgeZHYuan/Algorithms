#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void test (const string& fileName) {
    ifstream myFile;
    myFile.open(fileName.c_str());

    vector<int> code;
    int n, input;
    myFile >> n;

    for (int i = 0; i < n; i++){
        myFile >> input;
        if (input == 0 && code.size() > 0) code.pop_back();
        else code.push_back(input);
    }
    int counter = 0;
    for (int i = 0; i < code.size(); i++) counter += code[i];
    cout << counter << endl;

    myFile.close();
}

int main()
{
//    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2015 SecondTime\\TestFiles\\s1\\testFile.txt");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2015 SecondTime\\TestFiles\\s1\\s1.1.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2015 SecondTime\\TestFiles\\s1\\s1.2.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2015 SecondTime\\TestFiles\\s1\\s1.3.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2015 SecondTime\\TestFiles\\s1\\s1.4.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2015 SecondTime\\TestFiles\\s1\\s1.5.in");

    return 0;
}
