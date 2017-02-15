#include <iostream>
#include <fstream>
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
    bool validNode = true;
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
            outList.insert(scanObject.townIndex);
            if (oldSize != outList.size()) validNode = true;
        }
    }
    return -1;
}

void test (const string& fileName){
    ifstream myFile;
    myFile.open (fileName.c_str());

    int numberOfTowns, numberOfPaths;
    myFile >> numberOfTowns >> numberOfPaths;

    vector<Node> towns;
    Node valueHolder;
    for (int a = 0; a < numberOfTowns; a++) towns.push_back(valueHolder);
    int townOne, townTwo, pathLength;
    for (int i = 0; i < numberOfPaths; i++){
        myFile >> townOne >> townTwo >> pathLength;
        townOne--; townTwo--;
        Path temp;
        temp.pathWeight = pathLength;
        temp.pathEnd = townTwo;
        towns[townOne].paths.push_back(temp);
        temp.pathEnd = townOne;
        towns[townTwo].paths.push_back(temp);
    }

    int x, y;
    myFile >> x >> y;

    myFile.close();
    cout << shortestPath (towns, x-1, y-1) << endl;
}

int main() {

    test("C:\\Users\\ayuan\\Desktop\\DikjtraAlgorithmTest\\TestFiles\\case1.txt");

    return 0;
}
