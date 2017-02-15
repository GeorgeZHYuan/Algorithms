/////////////////////***************  BREADTHFIRST ALGORITHM **************////////////////////

#include <queue>  //scanlist
#include <vector> // theNode
#include <set>  // outlist

using namespace std;

struct Node {
    vector<int> connectedNodes;
};

struct ListItem {
    int arrayIndex;
    int distanceTraveled;
    ListItem (){}
    ListItem (int _arrayIndex, int _distanceTraveled){
        arrayIndex = _arrayIndex;
        distanceTraveled = _distanceTraveled;
    }
    void setListItem (int _arrayIndex, int _distanceTraveled){
        arrayIndex = _arrayIndex;
        distanceTraveled = _distanceTraveled;
    }
};

int findShortestConnection (int one, int two, vector<Node> theNode;{
    queue<ListItem> scanList;
    set<int> outList;
    ListItem valueHolder (one, -1); // <-- value may change between -1 and 0 depending on what is considered '1 away'
    scanList.push(valueHolder);
    outList.insert(one);
    while (!scanList.empty()){
        ListItem currentItem (scanList.front());
        scanList.pop();
        if (currentItem.arrayIndex == two) return currentItem.distanceTraveled;
        for (int i = 0; i < theNode[currentItem.arrayIndex].connectedNodes.size(); i++){
            int setSize = outList.size();
            outList.insert(theNode[currentItem.arrayIndex].connectedNodes[i]);
            if (outList.size() == setSize+1){
                valueHolder.setListItem(theNode[currentItem.arrayIndex].connectedNodes[i], currentItem.distanceTraveled+1);
                scanList.push(valueHolder);
            }
        }
    }
    return -1;
}
