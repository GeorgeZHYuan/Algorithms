#include <iostream>

using namespace std;

int main()
{
    int x;
    cin >> x;
    if (x == 1 || x == 9 || x == 10) cout << 1;
    else if (x == 2 || x == 3 || x == 7 || x == 8) cout << 2;
    else if (x == 4 || x == 5 || x == 6) cout << 3;

    return 0;
}
