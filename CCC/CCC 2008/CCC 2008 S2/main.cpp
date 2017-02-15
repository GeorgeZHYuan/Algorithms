#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>

using namespace std;

void test (const string& fileName){
    ifstream myFile;
    myFile.open(fileName.c_str());

    int temp;
    vector<int> radius;

    while (true){
        myFile >> temp;
        if (temp == 0) break;
        radius.push_back(temp);
    }

    myFile.close();

    for (int j = 0; j < radius.size(); j++){
        int totalPennies = 0;
        for (int i = radius[j]; i >= radius[j]*-1; i--) totalPennies += floor(sqrt(abs(pow(radius[j],2)-pow(i,2))))*2+1;
        cout << totalPennies << endl;
    }
    cout << endl;
}

int main()
{

//    test("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2008\\TestFiles\\s1\\SelfTest.txt");
    test("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2008\\TestFiles\\s2\\s2.1.in");
    test("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2008\\TestFiles\\s2\\s2.2.in");
    test("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2008\\TestFiles\\s2\\s2.3.in");
    test("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2008\\TestFiles\\s2\\s2.4.in");
    test("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2008\\TestFiles\\s2\\s2.5.in");

    return 0;
}
