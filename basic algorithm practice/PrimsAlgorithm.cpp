/////////////////////***************  PRIM'S ALGORITHM **************////////////////////

#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

struct Node {
    vector<pair<int,int> > paths;
};

struct ListItem {
    int id;
    int pathValue;
    ListItem () {}
    ListItem (int a, int b): id(a), pathValue(b){}
    ListItem returnValue (int a, int b) {
        ListItem temp (a,b);
        return temp;
    }
};

struct CompareListItem {
    bool operator () (ListItem& a, ListItem& b) {
        return a.pathValue > b.pathValue;
    }
};

int prim (vector<Node>& graph) {
    int total = 0;
    set<int> outList;
    ListItem valueHolder;
    priority_queue <ListItem, vector<ListItem>, CompareListItem> scanList;
    scanList.push(valueHolder.returnValue(0, 0));
    outList.insert(0);
    while (outList.size() != graph.size() && !scanList.empty()) {
        valueHolder = scanList.top();
        scanList.pop();
        for (int i = 0; i < graph[valueHolder.id].paths.size(); i++){
            ListItem curScan (graph[valueHolder.id].paths[i].second, graph[valueHolder.id].paths[i].first);
            if (outList.count(curScan.id) == 0) scanList.push(curScan);
        }
        while (!scanList.empty()){
            if (outList.count(scanList.top().id) == 0) break;
            scanList.pop();
        }
        total += scanList.top().pathValue;
        outList.insert(scanList.top().id);
    }
    if (outList.size() != graph.size()) return 9999999999;
    return total;
}
