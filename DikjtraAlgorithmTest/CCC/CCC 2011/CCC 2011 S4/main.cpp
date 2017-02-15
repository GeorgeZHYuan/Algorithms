#include <iostream>
#include <fstream>

using namespace std;

void test (const string& fileName){
    ifstream myFile;
    myFile.open(fileName.c_str());

    // O- O+ A- A+ B- B+ AB- AB+
    int bloodStorage [8];
    int peopleInNeed [8];

    for (int i = 0; i < 8; i++){
        myFile >> bloodStorage [i];
    }
    for (int i = 0; i < 8; i++){
        myFile >> peopleInNeed [i];
    }

    myFile.close();

    int totalPeople = 0;
    for (int i = 0; i < 8; i++){
        while(true){
            if (peopleInNeed [i] <= 0){
                break;
            }
            else {
                if (bloodStorage[i] > 0){
                    bloodStorage[i]--;
                    peopleInNeed[i]--;
                    totalPeople++;
                }
                else {
                    bool noneLeft = true;
                    for (int j = i; j >= 0; j--){
                        if (bloodStorage[j] > 0){
                            bloodStorage[j]--;
                            peopleInNeed[i]--;
                            totalPeople++;
                            noneLeft = false;
                            break;
                        }
                    }
                    if (noneLeft) {
                        break;
                    }
                }
            }
        }
    }

    cout << totalPeople << endl;
}

int main()
{
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2011\\TestFiles\\s4\\s4.1.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2011\\TestFiles\\s4\\s4.2.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2011\\TestFiles\\s4\\s4.3.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2011\\TestFiles\\s4\\s4.4.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2011\\TestFiles\\s4\\s4.5.in");
    return 0;
}
