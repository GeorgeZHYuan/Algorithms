/////////////////////***************  SET **************////////////////////

#include <iostream> // cout
#include <set> // set

using namespace std;

int main()
{
    set<int> existings;

    for (int i = 0; i < 10; i++) existings.insert(i);

    if (existings.find(5) != existings.end()) {
        cout << "Contains 5" << endl;
    }

    if (existings.find(15) == existings.end()) {
        cout << "Not contains 15" << endl;
    }

    // erase by iterator
    set<int>::iterator it = existings.begin(); it++;
    existings.erase (it);

    // erase by value
    existings.erase (4);
    return 0;
}
