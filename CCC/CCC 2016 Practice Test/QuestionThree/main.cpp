#include <iostream>
#include <map>
#include <vector>
#include <queue>
//10 1 1 1 2 2 2 3 3 3 3
using namespace std;

struct SortByBiggest{
    bool operator () (pair<int, int>& a, pair<int, int>& b){
        if (a.second == b.second) return a.first<b.first;
        else return a.second<b.second;
    }
};
struct SortBySmallest{
    bool operator () (pair<int, int>& a, pair<int, int>& b){
        if (a.second == b.second) return a.first>b.first;
        else return a.second<b.second;
    }
};


int main()
{
    int numberOfSensors, x;
    vector<pair<int, int> > readings;
    map<int, int> knownReadings;
    cin >> numberOfSensors;
    for (int i = 0; i < numberOfSensors; i++){
        cin >> x;
        if (knownReadings.count(x) == 0) knownReadings[x] = 1;
        else knownReadings[x]++;
    }

    priority_queue<pair<int, int> , vector<pair<int, int> >, SortByBiggest > bigList;
    for (map<int, int>::iterator it = knownReadings.begin(); it != knownReadings.end(); it++){
        bigList.push(*it);
    }

    priority_queue<pair<int, int> , vector<pair<int, int> >, SortBySmallest > smallList;
    for (map<int, int>::iterator it2 = knownReadings.begin(); it2 != knownReadings.end(); it2++){
        smallList.push(*it2);
    }
    pair<int, int> mostFrequentHigh = bigList.top();
    pair<int, int> mostFrequentLow = smallList.top();

    if (bigList.top().first != smallList.top().first){
        cout << bigList.top().first - smallList.top().first;
    }
    else {
        bigList.pop();
        smallList.pop();
        int pos1 = max(mostFrequentHigh.first - bigList.top().first, -1*(mostFrequentHigh.first - bigList.top().first));
        int pos2 = max(mostFrequentHigh.first - smallList.top().first, -1*(mostFrequentHigh.first - smallList.top().first));
        cout << max(pos1,pos2);
    }

    return 0;
}
