#include <iostream> // cout
#include <string> // string
#include <cstdio> // sprintf

using namespace std;

int main()
{
    int myint = 100;

    char buffer [256];
    sprintf(buffer, "%d", myint);
    cout << buffer << endl;

    string str = string(buffer);
    cout << str << endl;

    return 0;
}
