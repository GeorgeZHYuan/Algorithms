#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <map>

using namespace std;

int recursion (int i){
    if (i == 0) return 1;
    if (i <= 0) return 0;
    else {
        return (i*recursion(i-1));
    }
}

int main()
{
    map<int,int> checker;
    checker[1] = 1;
    checker[2] = 1;
    checker[3] = 1;
    cout << checker[1] << endl;

    if (checker.find(0) == checker.end()) cout << "none in here" << endl;
    for (map<int,int>::iterator it = checker.begin(); it != checker.end(); it++){
        cout << it->first << " " << it->second << endl;
    }
    return 0;
}
