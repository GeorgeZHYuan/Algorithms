#include <iostream>
#include <queue>
#include <map>
#include <math.h>

using namespace std;

map<int,int> values;

struct ListItem {
    int factorA;
    int factorB;

    ListItem () {
        factorA = 0;
        factorB = 0;
    }

    ListItem (int a, int b) {
        factorA = a;
        factorB = b;
    }

    int getScore () {
        return floor(factorA/factorB);
    }
};

struct CompareListItem {
    bool operator()(ListItem& one, ListItem& two)
    {
        if (one.getScore() < two.getScore()) return false;
        return true;
    }
};

int minCost (int currentNumber, int currentSmallest) {
    if (currentNumber == 1) return 0;
    else if (values[currentNumber] != 0) return values[currentNumber];
    else {
        priority_queue<ListItem, vector<ListItem>, CompareListItem> scanList;
        for (int i = 1; i <= floor(currentNumber/2); i++) {
            if ((currentNumber-i)%i == 0 && (currentNumber-i)/i < currentSmallest) {
                ListItem temp (currentNumber-i, i);
                scanList.push(temp);
                if ((currentNumber-i)/i == 2) break;
            }
        }
        while (!scanList.empty()) {
            ListItem temp = scanList.top(); scanList.pop();
            if (temp.getScore() >= currentSmallest) continue;
            int totalScore = temp.getScore() + minCost(temp.factorA, currentSmallest);
            if (values[temp.factorA] == 0) values[temp.factorA] = totalScore;
            else values[temp.factorA] = min (values[temp.factorA], totalScore);
            currentSmallest = min (currentSmallest, totalScore);
        }
        return currentSmallest;
    }
}

int main()
{
    int goal;
    cin >> goal;
    cout << minCost (goal) << endl;
    return 0;
}
