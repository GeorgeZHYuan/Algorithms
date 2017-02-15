#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstdio>

using namespace std;

void test (const string& fileName) {
    ifstream myFile;
    myFile.open(fileName.c_str());

    int maxWeight;
    int carNumber;
    vector<int> cars;

    myFile >> maxWeight >> carNumber;

    int temp;
    for (int i = 0; i < carNumber; i++) {
        myFile >> temp;
        cars.push_back(temp);
    }

    myFile.close();

    int bridgeWeight = 0;
    int numberOfCars = 0;
    for (int i = 0; i < carNumber; i++) {
        if (bridgeWeight + cars[i] <= maxWeight) {
            bridgeWeight += cars[i];
            if (i >= 3) bridgeWeight -= cars [i - 3];
            numberOfCars++;
        }
        else {
            break;
        }
    }
    cout << numberOfCars << endl;
}

int main()
{
//    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013 SecondTime\\TestFiles\\S2\\test1.txt");
//    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013 SecondTime\\TestFiles\\S2\\test2.txt");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013 SecondTime\\TestFiles\\S2\\s2.1.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013 SecondTime\\TestFiles\\S2\\s2.2.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013 SecondTime\\TestFiles\\S2\\s2.3.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013 SecondTime\\TestFiles\\S2\\s2.4.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013 SecondTime\\TestFiles\\S2\\s2.5.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013 SecondTime\\TestFiles\\S2\\s2.6.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013 SecondTime\\TestFiles\\S2\\s2.7.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013 SecondTime\\TestFiles\\S2\\s2.8.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013 SecondTime\\TestFiles\\S2\\s2.9.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013 SecondTime\\TestFiles\\S2\\s2.10.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013 SecondTime\\TestFiles\\S2\\s2.11.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013 SecondTime\\TestFiles\\S2\\s2.12.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013 SecondTime\\TestFiles\\S2\\s2.13.in");

    return 0;
}
