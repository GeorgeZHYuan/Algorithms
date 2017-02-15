#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    double startNumber;
    double endNumber;
    double sub;
    int coolNumbers = 0;

    cin >> startNumber >> endNumber;

    int counter = floor (pow(startNumber, 1/3.));
    sub = pow (counter, 3);

    while (true){
        if (sub >= startNumber){
            if (pow (sub, 1/2.) == floor (pow (sub, 1/2.))){
                coolNumbers ++;
            }
        }

        counter ++;
        sub = pow (counter, 3);
        if (sub > endNumber){
            break;
        }
    }

    cout << coolNumbers << endl;

    return 0;
}
