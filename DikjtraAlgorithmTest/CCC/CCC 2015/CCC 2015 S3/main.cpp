#include <iostream>

using namespace std;

int main()
{
    int numberOfDocks;
    cin >> numberOfDocks;
    bool docks [numberOfDocks];
    for (int i = 0; i < numberOfDocks; i++) docks[i] =true;
    int numberOfPlanes;
    cin >> numberOfPlanes;
    int total = 0;
    for (int i = 0; i < numberOfPlanes; i++){
        int temp;
        cin >> temp;
        temp--;
        bool found = false;
        for (int j = temp; j >= 0; j--){
            if (docks[j]) {
                docks[j] = false;
                total ++;
                found = true;
                break;
            }

        }
        if (!found) break;
    }
    if (total > numberOfDocks) total = numberOfDocks;
    cout << total;

    return 0;
}
