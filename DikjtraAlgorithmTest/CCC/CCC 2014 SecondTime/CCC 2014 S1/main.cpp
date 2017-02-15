#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void test (const string& fileName) {
    ifstream myFile;
    myFile.open(fileName.c_str());

    int numberOfPeople;
    myFile >> numberOfPeople;
    vector<int> people;
    for (int i = 1; i <= numberOfPeople; i++) people.push_back(i);

    int roundsOfElimination, temp;
    myFile >> roundsOfElimination;
    for (int i = 0; i < roundsOfElimination; i++){
        myFile >> temp;
        int counter = 0;
        for (int i = 0; i < people.size(); i++){
            counter++;
            if (counter == temp) {
                people.erase(people.begin()+i);
                counter = 1;
            }
            if (people.size() == 0) break;
        }
    }
    for (int i = 0; i < people.size(); i++) cout << people[i] << endl;
    cout << endl;
    myFile.close();
}

int main()
{
//    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2014 SecondTime\\TestFiles\\s1\\testFile.txt");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2014 SecondTime\\TestFiles\\s1\\s1.1.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2014 SecondTime\\TestFiles\\s1\\s1.2.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2014 SecondTime\\TestFiles\\s1\\s1.3.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2014 SecondTime\\TestFiles\\s1\\s1.4.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2014 SecondTime\\TestFiles\\s1\\s1.5.in");
    return 0;
}
