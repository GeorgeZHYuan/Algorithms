/////////////////////***************  DIJKTRA'S ALGORITHM **************////////////////////

#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

struct Path {
    int pathEnd;
    int pathWeight;
};

struct Node {
    vector<Path> paths;
};

struct ListItem {
    int townIndex;
    int totalDistance;
    ListItem (int a, int b){
        townIndex = a;
        totalDistance = b;
    }
    void setValues (ListItem theTown){
        townIndex = theTown.townIndex;
        totalDistance = theTown.totalDistance;
    }
};

struct CompareListItem {
    bool operator () (ListItem& one, ListItem& two){
        return one.totalDistance > two.totalDistance;
    }
};

int shortestPath (vector<Node>& towns, int startTown, int endTown){
    priority_queue<ListItem, vector<ListItem>, CompareListItem> scanList;
    set<int> outList;
    ListItem scanObject (startTown, 0);
    outList.insert(startTown);
    int validNode = true;
    while (validNode){
        validNode = false;
        if (scanObject.townIndex == endTown) return scanObject.totalDistance;
        for (int i = 0; i < towns[scanObject.townIndex].paths.size(); i++){
            ListItem valueHolder (towns[scanObject.townIndex].paths[i].pathEnd, scanObject.totalDistance + towns[scanObject.townIndex].paths[i].pathWeight);
            scanList.push(valueHolder);
        }
        while (!scanList.empty() && !validNode){
            scanObject.setValues(scanList.top());
            scanList.pop();
            int oldSize = outList.size();
            outList.insert(scanList.top().townIndex);
            if (oldSize != outList.size()) validNode = true;
        }
    }
    return -1;
}
