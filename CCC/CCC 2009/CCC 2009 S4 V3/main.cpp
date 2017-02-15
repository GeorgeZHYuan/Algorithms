#include <iostream>
#include <fstream>
#include <set>
#include <queue>
#include <vector>

using namespace std;

struct Path {
    int pathEnd;
    int value;

    Path (int id, int _value) {
        pathEnd = id;
        value = _value;
    }
};

struct Node {
    vector<Path> paths;
    int worth = -1;

    void addPath (int id, int _value) {
        Path temp (id, _value);
        paths.push_back(temp);
    }
};

struct ListItem {
    int id;
    int weight = 0;

    ListItem () {};
    ListItem (int a, int b) {
        id = a;
        weight = b;
    };
    void setValue (int a, int b) {
        id = a;
        weight = b;
    };
};

class CompareListItem {
public:
    bool operator ()(ListItem& one, ListItem& two){
        if (one.weight >= two.weight) return true;
        return false;
    }
};

int cheapestRoute (Node cities [], int destination) {
    int bestCost = 2147483647;
    priority_queue <ListItem, vector<ListItem>, CompareListItem> scanList;
    set<int> outlist;

    ListItem temp (destination, 0);
    scanList.push(temp);

    while (!scanList.empty()) {
        ListItem curNode (scanList.top().id, scanList.top().weight);
        outlist.insert(curNode.id);
        scanList.pop();

        if (curNode.weight >= bestCost) return bestCost;
        if (cities[curNode.id].worth != -1) bestCost = min(cities[curNode.id].worth + curNode.weight, bestCost);
        for (int i = 0; i < cities[curNode.id].paths.size(); i++){
            if (outlist.find(cities[curNode.id].paths[i].pathEnd) == outlist.end()) {
                temp.setValue(cities[curNode.id].paths[i].pathEnd, curNode.weight + cities[curNode.id].paths[i].value);
                scanList.push(temp);
            }
        }
    }
    return bestCost;
}

void test (const string& fileName){
    ifstream myFile;
    myFile.open(fileName.c_str());

    int N, T, K, a, b, c, destination;

    myFile >> N >> T;
    Node cities [N];


    for (int i = 0; i < T; i++) {
        myFile >> a >> b >> c;
        a--;b--;
        cities[a].addPath(b, c);
        cities[b].addPath(a, c);
    }

    myFile >> K;
    for (int i = 0 ; i < K; i++) {
        myFile >> a >> b;
        a--;
        cities[a].worth = b;
    }

    myFile >> destination; destination--;

    cout << cheapestRoute (cities, destination) << endl;

    myFile.close();
}

int main()
{
//    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2009\\TestFiles\\s4\\test.txt");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2009\\TestFiles\\s4\\s4.1.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2009\\TestFiles\\s4\\s4.2.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2009\\TestFiles\\s4\\s4.3.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2009\\TestFiles\\s4\\s4.4.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2009\\TestFiles\\s4\\s4.5.in");

    return 0;
}
