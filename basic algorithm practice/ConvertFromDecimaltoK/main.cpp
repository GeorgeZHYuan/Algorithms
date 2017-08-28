//////////****** CONVERT_FROM_DECIMAL_TO_K *******/////////

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main()
{
    // num stores a value in base 10
    // solution will have digits in an array
    int num = 10;
    int K = 6;

    vector<int> digit;
    int result;

    while ( num != 0 )
    {
        int remainder;
        remainder = num % K ;  // assume K > 1
        num = num / K ;  // integer division
        digit.push_back(remainder);
    }

    for (int i = 0; i < digit.size(); i++) {
        result += digit[i] * pow(10,digit.size()-(1+i));
    }

    cout << result << endl;


    return 0;
}
