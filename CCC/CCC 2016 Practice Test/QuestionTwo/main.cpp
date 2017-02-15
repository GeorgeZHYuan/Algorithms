#include <iostream>

using namespace std;

int result (int humidity, int waitTime){
    if (waitTime == 0) return -1;
    for (int i = 1; i <= waitTime; i++) {
        if ((-6*(i*i*i*i) + (humidity*(i*i*i))+(2*(i*i)+i)) <= 0) return i;
    }
    return -1;
}

int main()
{
    int humidity, waitTime;
    cin >> humidity >> waitTime;
    int landTime = result(humidity, waitTime);
    if (landTime != -1) cout << "The balloon first touches ground at hour:" << endl << landTime;
    else cout << "The balloon does not touch ground in the given time.";
    return 0;
}
