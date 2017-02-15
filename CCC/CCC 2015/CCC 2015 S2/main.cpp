#include <iostream>
#include <vector>

using namespace std;

bool isOk (char a, char b){
    if (a == 'L' && b == 'L') return true;
    if (a == 'M' && b != 'S') return true;
    if (a == 'S') return true;
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
    double total = 0;
    for (double i = 0; i < numberOfPlayers; i++){
        char theSize;
        int number;
        cin >> theSize >> number;
        number--;
//cout << "size: " << theSize << " number: " << number << endl;
//cout << "Jersey picked: " << jerseys[number] << endl;
        if (jerseys[number] != 'b' && isOk (theSize, jerseys[number])){
             jerseys[number] = 'b';
             total ++;
        }
    }

    cout << total;
    return 0;
}
