#include <iostream>

using namespace std;

int main () {
    int goal;
    int cost = 0;
    cin >> goal;
    while (goal != 1) {
        for (int i = 2; i <= goal; i++){
            if (goal%i == 0) {
                cost += (goal - (goal/i))/(goal/i);
                goal -= goal/i;
                break;
            }
        }
    }
    cout << cost << endl;
    return 0;
}
