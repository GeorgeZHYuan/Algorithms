#include <iostream>
#include <fstream>
#include <map>

using namespace std;

void test (const string& fileName){
    ifstream myFile;
    myFile.open(fileName.c_str());

    int mini, maxi;
    int counter = 0;
    map <int, int> numbers;

    myFile >> mini >> maxi;

    for (int i = 1; i < maxi; i++){
        int temp = i*i*i;
        if (temp > maxi) break;
        if (temp >= mini && temp <= maxi) numbers[temp] = 5;
    }

    for (int i = 1; i < maxi; i++){
        int temp = i*i;
        if (temp > maxi) break;
        if (numbers[temp] !=  NULL) counter++;
    }

    cout << counter << endl;

    myFile.close();
}

int main() {
//    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2009 SecondTime\\TestFiles\\s1\\testFile.txt");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2009 SecondTime\\TestFiles\\s1\\s1.1.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2009 SecondTime\\TestFiles\\s1\\s1.2.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2009 SecondTime\\TestFiles\\s1\\s1.3.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2009 SecondTime\\TestFiles\\s1\\s1.4.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2009 SecondTime\\TestFiles\\s1\\s1.5.in");

    return 0;
}


