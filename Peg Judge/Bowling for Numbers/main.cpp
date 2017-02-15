#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int testFiles;
    cin >> testFiles;

    for (int i = 0; i < testFiles; i++){
        int p, b, w;
        cin >> p >> b >> w;

        int pins [p];
        int sumList [p];
        int newList [p];
        vector<int> oldList;

        for (int i = 0; i < p; i++) {
            cin >> pins[i];
            sumList[i] = 0;
            oldList.push_back(0);
        }

        sumList[0] = pins[0];
        for (int i = 1; i < p; i++) {
            for (int j = 0; j < w && i-j > -1 ; j++) sumList[i] += pins[i-j];
        }

        newList[0] = pins[0];
        for (int ballNumber = 0; ballNumber < b; ballNumber++) {
            for (int pinNumber = 1; pinNumber < p; pinNumber++) {
                if (pinNumber < w) newList[pinNumber] = pins[pinNumber] + newList[pinNumber-1];
                else newList[pinNumber] = max(sumList[pinNumber] + oldList[pinNumber - w], newList[pinNumber-1]);
            }
            oldList.assign(newList, newList+p);
        }
        cout << oldList[p-1] << endl;
    }cout << endl;
}
