#include <iostream>
#include <fstream>
#include <set>
#include <queue>
#include <vector>

using namespace std;

struct Path {
    int pathEnd;
    int pathWeight;
};

struct Node {
    vector<Path> paths;
    int costOfPencil;
};

class ListItem {
public:
    int arrayIndex;
    int weight;

    ListItem () {}
    ListItem (int _arrayIndex, int _weight){
        arrayIndex = _arrayIndex;
        weight = _weight;
    }

    void setListItem (int _arrayIndex, int _weight){
        arrayIndex = _arrayIndex;
        weight = _weight;
    }
};

class CompareListItem {
public:
    bool operator ()(ListItem& one, ListItem& two){
        if (one.weight >= two.weight) return true;
        return false;
    }
};

// using priority queue (fail so far)
int cheapestWay (int destination, Node towns [], int numberOfTowns){
    int cheapestCost = 999999;
    priority_queue <ListItem, vector<ListItem>, CompareListItem> scanList;
    set<int> outList;
    ListItem valueHolder(destination, 0);
    scanList.push(valueHolder);
    int counter = 0;

    while (!scanList.empty()){
        ListItem currentItem(scanList.top());
        outList.insert(scanList.top().arrayIndex);
        scanList.pop();

        if (currentItem.weight >= cheapestCost) return cheapestCost;
        if (towns[currentItem.arrayIndex].costOfPencil > 0 && currentItem.weight + towns[currentItem.arrayIndex].costOfPencil < cheapestCost){
            cheapestCost = currentItem.weight + towns[currentItem.arrayIndex].costOfPencil;
        }
        for (int i = 0; i < towns[currentItem.arrayIndex].paths.size(); i++){
            if (outList.find(towns[currentItem.arrayIndex].paths[i].pathEnd) == outList.end()) {
                valueHolder.setListItem(towns[currentItem.arrayIndex].paths[i].pathEnd, currentItem.weight+towns[currentItem.arrayIndex].paths[i].pathWeight);
                scanList.push(valueHolder);
            }
        }
        int sub = scanList.size();
        for (int i = 0; i < sub; i++){
            if (outList.find(scanList.top().arrayIndex) == outList.end()){
                break;
            }
            else {
                scanList.pop();
            }
        }
    }
    return cheapestCost;
}

int main () {

    int numberOfTowns;
    int numberOfTradeRoutes;
    int townsWithPencils;
    int destination;

    cin >> numberOfTowns;
    Node towns [numberOfTowns];
    for (int i = 0; i < numberOfTowns; i++) towns[i].costOfPencil = 0;

    cin >> numberOfTradeRoutes;

    Path valueHolder;
    int townOne, townTwo, pathWeight;
    for (int i = 0; i < numberOfTradeRoutes; i++){
        cin >> townOne >> townTwo >> pathWeight;
        townOne--;
        townTwo--;
        valueHolder.pathWeight = pathWeight;
        valueHolder.pathEnd = townTwo;
        towns[townOne].paths.push_back(valueHolder);
        valueHolder.pathEnd = townOne;
        towns[townTwo].paths.push_back(valueHolder);
    }

    cin >> townsWithPencils;

    for (int i = 0; i < townsWithPencils; i++){
        int townIndex, cost;
        cin >> townIndex >> cost;
        towns [townIndex -1].costOfPencil = cost;
    }

    cin >> destination;
    destination--;

    cout << cheapestWay (destination, towns, numberOfTowns) << endl;
    return 0;
}
