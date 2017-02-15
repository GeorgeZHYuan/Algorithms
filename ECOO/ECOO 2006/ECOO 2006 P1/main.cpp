#include <iostream>

using namespace std;

int main()
{
    int lifeSpan, monthsToCalculate;
    cin >> lifeSpan >> monthsToCalculate;
    int timeLine [monthsToCalculate+lifeSpan-1];
    int previousSum = 0;
    int endMarker = monthsToCalculate+lifeSpan-2;
    int startMarker = endMarker - lifeSpan + 1;
    timeLine[startMarker] = 1;
    for (int i = 1; i < lifeSpan; i++) timeLine[startMarker+i] = 0;
    for (int i = 1; i <= monthsToCalculate; i++){
        timeLine[startMarker-i] = previousSum;
        previousSum = previousSum - timeLine[endMarker-i] + timeLine[startMarker - i + 1];
    }
    int sum = 0;
    for (int i = 0; i < lifeSpan; i++) sum += timeLine[i];
    cout << sum << endl;
    return 0;
}
