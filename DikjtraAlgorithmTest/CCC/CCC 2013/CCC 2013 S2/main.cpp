#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void test (const string& fileName){
    ifstream myFile;
    myFile.open(fileName.c_str());
    int numberOfCars;
    int maxWeight;
    myFile >> maxWeight >> numberOfCars;
    vector<int> cars;
    int sub;
    for (int i = 0; i < numberOfCars; i++){
        myFile >> sub;
        cars.push_back(sub);
    }
    myFile.close();

    int currentWeight = 0;
    int passedCars = 0;
    int carsOn = 0;
    for (int i = 0; i < cars.size(); i++){
        if (carsOn == 4){
            currentWeight -= cars[i-4];
            carsOn --;
            passedCars++;
        }
        if (cars[i] + currentWeight > maxWeight){
            passedCars += carsOn;
            break;
        }
        else {
            carsOn++;
            currentWeight += cars[i];
            if (i == cars.size()-1){
                passedCars += carsOn;
            }
        }
    }
    cout << passedCars << endl;
}

int main() {
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013\\TestFiles\\S2\\s2.1.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013\\TestFiles\\S2\\s2.2.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013\\TestFiles\\S2\\s2.3.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013\\TestFiles\\S2\\s2.4.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013\\TestFiles\\S2\\s2.5.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013\\TestFiles\\S2\\s2.6.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013\\TestFiles\\S2\\s2.7.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013\\TestFiles\\S2\\s2.8.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013\\TestFiles\\S2\\s2.9.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013\\TestFiles\\S2\\s2.10.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013\\TestFiles\\S2\\s2.11.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013\\TestFiles\\S2\\s2.12.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013\\TestFiles\\S2\\s2.13.in");
    return 0;
}
