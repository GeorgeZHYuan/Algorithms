#include <iostream>

using namespace std;

int main()
{
    int pattern [2];
    int counting = 2;
    int temp;

    cin >> pattern [0] >> pattern [1];

    while (true){
        if (pattern[0] >= pattern[1]){
            temp = pattern [0] - pattern [1];
            pattern [0] = pattern [1];
            pattern [1] = temp;
            counting += 1;
        }
        else {
            break;
        }
    }
    cout << counting << endl;

    return 0;
}
