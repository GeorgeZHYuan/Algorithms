#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void test (const string& fileName) {
    ifstream myFile;
    myFile.open(fileName.c_str());

    vector<bool> jerseyIsAvailible [3];
    vector<char> jerseyNumber;

    int numberOfJerseys, numberOfAthletes;
    myFile >> numberOfJerseys >> numberOfAthletes;


    for (int i = 0; i < 3; i++){
        for (int j = 0; j < numberOfJerseys; j++){
            bool temp = false;
            jerseyIsAvailible[i].push_back(temp);
        }
    }
    char temp = 'E';
    for (int i = 0; i < numberOfAthletes; i++) jerseyNumber.push_back(temp);

    char x;
    for (int i = 0; i < numberOfJerseys; i++){
         myFile >> x;
         if (x == 'L') {
                jerseyIsAvailible [2][i] = true;
                jerseyIsAvailible [1][i] = true;
                jerseyIsAvailible [0][i] = true;
         }
         else if (x == 'M') {
                jerseyIsAvailible [1][i] = true;
                jerseyIsAvailible [0][i] = true;
         }
         else if (x == 'S') jerseyIsAvailible [0][i] = true;
    }

    char y;
    int z;
    for (int i = 0; i < numberOfAthletes; i++){
        myFile >> y >> z;
        z--;
        if (z < 0 || z >= numberOfJerseys) continue;
        else if (jerseyNumber[z] == 'E' || jerseyNumber[z] == 'L') jerseyNumber[z] = y;
        else if (jerseyNumber[z] == 'M' && y != 'L') jerseyNumber[z] = y;
        else if (jerseyNumber[z] == 'S' && y == 'S') jerseyNumber[z] = y;
    }

    int counter = 0;
    for (int i = 0; i < numberOfAthletes; i++) {
        char charConv;
        if (jerseyNumber[i] != 'E'){
            if (jerseyNumber[i] == 'L') charConv = 2;
            else if (jerseyNumber[i] == 'M') charConv = 1;
            else if (jerseyNumber[i] == 'S') charConv = 0;

            if (jerseyIsAvailible[charConv][i]) {
                counter++;
                jerseyIsAvailible[2][i] = false;
                jerseyIsAvailible[1][i] = false;
                jerseyIsAvailible[0][i] = false;
            }
        }
    }

    cout << counter << endl;
    myFile.close();
}

int main()
{
//    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2015 SecondTime\\TestFiles\\s2\\testFile.txt");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2015 SecondTime\\TestFiles\\s2\\s2.1.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2015 SecondTime\\TestFiles\\s2\\s2.2.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2015 SecondTime\\TestFiles\\s2\\s2.3.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2015 SecondTime\\TestFiles\\s2\\s2.4.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2015 SecondTime\\TestFiles\\s2\\s2.5.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2015 SecondTime\\TestFiles\\s2\\s2.6.in");

    return 0;
}
