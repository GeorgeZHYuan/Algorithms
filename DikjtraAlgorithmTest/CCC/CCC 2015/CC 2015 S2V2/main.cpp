#include <iostream>
#include <vector>

using namespace std;

bool isOk (char a, char b){
    if (a == 'S' && b == 'S') return true;
    if (a == 'M' && b != 'L') return true;
    if (a == 'M') return true;
    return false;

}

int main()
{
    double numberOfJerseys, numberOfPlayers;
    cin >> numberOfJerseys >> numberOfPlayers;
    vector<char> jerseys;
    char temp;

    for (double i = 0; i < numberOfJerseys; i++){
        cin >> temp;
        jerseys.push_back(temp);
    }

    vector<int> smalls;
    vector<int> mediums;
    vector<int> large;
    double total = 0;
    for (double i = 0; i < numberOfPlayers; i++){
        double theSize, number;
        cin >> theSize >> number;
        number--;

    }

    cout << total;
    return 0;
}
