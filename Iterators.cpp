/////////////////////***************  ITERATORS **************////////////////////

#include <iostream> // cout
#include <vector> // vector
#include <string> // string
#include <cstdio> // sprintf

using namespace std;

int main()
{
    vector<string> lst;

    char buffer [256];
    for (int i = 0; i < 10; i++) {
        sprintf(buffer, "%d", i);
        lst.push_back(string(buffer));
    }

    for (vector<string>::iterator it = lst.begin(); it != lst.end(); ++it) {
        cout << (*it) << endl; // always bracket *lt
    }

    return 0;
}
