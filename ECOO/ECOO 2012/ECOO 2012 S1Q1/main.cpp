#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

void test (const string& fileName) {
    ifstream myFile;
    myFile.open(fileName.c_str());
    string firstWords [3];
    for (int i = 0; i < 3; i++){
        myFile >> firstWords [i];
    }
    string theSeason = firstWords[0] + " " + firstWords[1] + " " + firstWords [2];
    cout << theSeason << endl;
    for (int i = 0; i < 20; i++) cout << "="; cout << endl;
    double total [2] = {0, 0};
    string theName;
    double gamesPlayed, atBats, runs, hitsTotal, twoBase, threeBase, fourBase;
    for (int i = 0; i < 10; i++) {
        double number [2];
        myFile >> theName >> gamesPlayed >> atBats >> runs >> hitsTotal >> twoBase >> threeBase >> fourBase;
        number [0] = hitsTotal/atBats;
        number [1] = ((hitsTotal-(twoBase+threeBase+fourBase)) + 2*twoBase + 3*threeBase + 4*fourBase)/atBats;
        total [0] += number[0]; total [1] += number[1];
        char buffer [256];
        sprintf(buffer, "%d", myint);
        cout << buffer << endl;
        cout << theName << ": " << number [0] << " " << number [1] << endl;
    }
    for (int i = 0; i < 20; i++) cout << "="; cout << endl;
    cout << "Big 10 Av: " << total[0]/10 << " " << total[1]/10 << endl << endl;
    myFile.close ();
}

int main()
{
    cout << fixed << setprecision(3) << endl;
    test ("C:\\Users\\ayuan\\Documents\\Computer\\ECOO\\ECOO 2012\\ECOO-CS Competition 2012\\Round 1\\Round 1\\data\\DATA11.txt");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\ECOO\\ECOO 2012\\ECOO-CS Competition 2012\\Round 1\\Round 1\\data\\DATA12.txt");

    return 0;
}
