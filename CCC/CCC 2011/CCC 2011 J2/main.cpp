#include <iostream>

using namespace std;

int power (int number, int power){
    int value = number;

    for (int i = 0; i < power-1; i++){
        value*=number;
    }

    return value;
}

bool calculate (int h, int t){
    for (int i = 1; i <= t; i++){
        if (-6*power(i,4) + h*power(i,3) + 2*power(i,2) + i <= 0){
            cout << "The balloon first touches ground at hour:\n" << i << endl;
            return true;
        }
    }

    cout << "The balloon does not touch ground in the given time." << endl;
    return false;
}

int main()
{
    int humidity;
    int timeWillingToWait;

    cin >> humidity >> timeWillingToWait;
    calculate(humidity, timeWillingToWait);

    return 0;
}
