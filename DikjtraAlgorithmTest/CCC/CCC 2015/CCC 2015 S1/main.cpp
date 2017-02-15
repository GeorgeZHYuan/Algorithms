#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int numberOfTrials;
    cin >> numberOfTrials;
    vector <int> numbers;
    int temp;
    for (int i = 0; i < numberOfTrials; i++){
        cin >> temp;
        if (temp != 0) numbers.push_back(temp);
        else numbers.erase(numbers.end()-1);
    }

    int total = 0;
    for (int i = 0; i < numbers.size(); i++){
        total += numbers[i];
    }
    cout << total;
    return 0;
}
