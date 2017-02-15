#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void test (const string& fileName){
    ifstream myFile;
    myFile.open(fileName.c_str());

    int maxWieght, carNumber, temp;
    myFile >> maxWieght >> carNumber;
    vector<int> carList;

    int totalWeight = 0, carsOnBridge = 0;
    for (int i = 0; i < carNumber; i++) {
        myFile >> temp;
        carList.push_back(temp);

        if (carsOnBridge >= 4) {
            totalWeight -= carList[i-4];
            carsOnBridge--;
//cout << "weight of " << carList[i-4] << " removed" << endl;
//cout << "total weight is now " << totalWeight << endl;
        }

        totalWeight += temp;
        carsOnBridge++;
//cout << "weight of " << temp << " added" << endl;

        if (totalWeight > maxWieght) {
            cout << i << endl;
            break;
        }

        if (i == carNumber-1) cout << i+1 << endl;
    }


    myFile.close();
}

int main()
{
//    test("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013 ThirdTime\\TestFiles\\s2\\testFile.txt");
    test("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013 ThirdTime\\TestFiles\\s2\\s2.1.in");
    test("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013 ThirdTime\\TestFiles\\s2\\s2.2.in");
    test("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013 ThirdTime\\TestFiles\\s2\\s2.3.in");
    test("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013 ThirdTime\\TestFiles\\s2\\s2.4.in");
    test("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013 ThirdTime\\TestFiles\\s2\\s2.5.in");
    test("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013 ThirdTime\\TestFiles\\s2\\s2.6.in");
    test("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013 ThirdTime\\TestFiles\\s2\\s2.7.in");
    test("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013 ThirdTime\\TestFiles\\s2\\s2.8.in");
    test("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013 ThirdTime\\TestFiles\\s2\\s2.9.in");
    test("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013 ThirdTime\\TestFiles\\s2\\s2.10.in");
    test("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013 ThirdTime\\TestFiles\\s2\\s2.11.in");
    test("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013 ThirdTime\\TestFiles\\s2\\s2.12.in");
    test("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013 ThirdTime\\TestFiles\\s2\\s2.13.in");

    return 0;
}
