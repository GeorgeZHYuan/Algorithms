#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

struct Node {
    int pencilCost = -1;
    vector<pair<int, int> > neighbors;
};

struct ComparePair {
    bool operator () (pair<int, int>& a, pair <int, int>& b){
        return a.second > b.second;
    }
};

int cheapestMethod (int reciever, vector<Node>& graph) {
    int bestCost = 9999999999;
    priority_queue<pair<int, int>, vector<pair<int, int> >, ComparePair> scanList;
    map<int, int> outList;
    for (int i = 0; i < graph.size(); i++) outList[i] = 5;
    scanList.push(pair<int, int>(reciever, 0));
    while (!scanList.empty()) {
        pair<int, int> curNode (scanList.top());
        scanList.pop();
        outList[curNode.first] = 10;
        if (graph[curNode.first].pencilCost != -1) bestCost = min(graph[curNode.first].pencilCost + curNode.second, bestCost);
        for (int i = 0; i < graph[curNode.first].neighbors.size(); i++){
            if (outList[graph[curNode.first].neighbors[i].first] == 5) {
                scanList.push(pair<int, int>(graph[curNode.first].neighbors[i].first, graph[curNode.first].neighbors[i].second + curNode.second));
            }
        }
        while (outList[scanList.top().first] == 10) {
            scanList.pop();
            if (scanList.empty() || scanList.top().second >= bestCost) return bestCost;
        }
    }

    return bestCost;
}

void test (const string& fileName){
    ifstream myFile;
    myFile.open(fileName.c_str());
    Node valueHolder;

    int nodeNumber, pathNumber, sellerNumber, a, b, c;
    vector<Node> towns;
    myFile >> nodeNumber >> pathNumber;
    for (int i = 0; i < nodeNumber; i++) towns.push_back(valueHolder);

    for (int i = 0; i < pathNumber; i++) {
        myFile >> a >> b >> c;
        a--; b--;
        towns[a].neighbors.push_back(pair<int, int> (b, c));
        towns[b].neighbors.push_back(pair<int, int> (a, c));
    }

    myFile >> sellerNumber;
    for (int i = 0; i < sellerNumber; i++) {
        myFile >> a >> c;
        a--;
        towns[a].pencilCost = c;
    }

    myFile >> a;
    a--;
    cout << cheapestMethod(a, towns) << endl;
    myFile.close();
}

int main()
{
//    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2009 SecondTime\\TestFiles\\s4\\testFile.txt");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2009 SecondTime\\TestFiles\\s4\\s4.1.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2009 SecondTime\\TestFiles\\s4\\s4.2.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2009 SecondTime\\TestFiles\\s4\\s4.3.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2009 SecondTime\\TestFiles\\s4\\s4.4.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2009 SecondTime\\TestFiles\\s4\\s4.5.in");
    return 0;
}
