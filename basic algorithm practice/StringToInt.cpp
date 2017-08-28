/////////////////////***************  STRING_TO_INT **************////////////////////

#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

int main()
{
    string myString = "10101";
    int stringValue = atoi(myString.c_str());
    cout << stringValue + 1 << endl;

    return 0;
}
