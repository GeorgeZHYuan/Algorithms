#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <set>
#include <queue>

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

void test (const string& fileName) {
    ifstream myFile;
    myFile.open(fileName.c_str());
    vector<Node> graph;
    map<pair<int,int>, pair<int,int> > edgeMap;
    int numberOfPens;
    myFile >> numberOfPens;
    Node valueHolder;
    pair<int,int> coordinates;
    for (int i = 0 ; i < numberOfPens; i++){
        graph.push_back(valueHolder);
        int numberOfEdges;
        myFile >> numberOfEdges;
        int verticies [numberOfEdges];
        int edgeValues [numberOfEdges];
        for (int j = 0; j < numberOfEdges; j++) myFile >> verticies[j];
        for (int j = 0; j < numberOfEdges; j++) myFile >> edgeValues[j];
        for (int j = 0; j < numberOfEdges-1; j++){
            coordinates = pair<int,int>(min(verticies[j], verticies[j+1]), max(verticies[j], verticies[j+1]));
            if (edgeMap.count(pair<int,int>(coordinates)) == 0) edgeMap[pair<int,int>(coordinates)] = pair<int,int>(i, edgeValues[j]);
            else {
                graph[i].paths.push_back(pair<int,int>(edgeValues[j], edgeMap[pair<int,int>(coordinates)].first));
                graph[edgeMap[pair<int,int>(coordinates)].first].paths.push_back(pair<int,int>(edgeValues[j], i));
                edgeMap.erase(pair<int,int>(coordinates));
            }
        }
        coordinates = pair<int,int> (min(verticies[0], verticies[numberOfEdges-1]), max(verticies[0], verticies[numberOfEdges-1]));
        if (edgeMap.count(coordinates) == 0) edgeMap[coordinates] = pair<int,int>(i, edgeValues[numberOfEdges-1]);
        else {
            graph[i].paths.push_back(pair<int,int>(edgeValues[numberOfEdges-1], edgeMap[coordinates].first));
            graph[edgeMap[coordinates].first].paths.push_back(pair<int,int>(edgeValues[numberOfEdges-1], i));
            edgeMap.erase(coordinates);
        }
    }
    int result1 = prim(graph);
    graph.push_back(valueHolder);
    for (map<pair<int,int>, pair<int,int> >::iterator it = edgeMap.begin(); it != edgeMap.end(); it++){
        graph[numberOfPens].paths.push_back(pair<int,int>(it->second.second, it->second.first));
        graph[it->second.first].paths.push_back(pair<int,int>(it->second.second, numberOfPens));
    }
    int result2 = prim(graph);
    cout << min(result1, result2) << endl;
}

int main () {
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2016 Practice Test\\QuestionFour\\TestFiles\\S4\\testCase.txt");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2016 Practice Test\\QuestionFour\\TestFiles\\S4\\s4.1.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2016 Practice Test\\QuestionFour\\TestFiles\\S4\\s4.2.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2016 Practice Test\\QuestionFour\\TestFiles\\S4\\s4.3.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2016 Practice Test\\QuestionFour\\TestFiles\\S4\\s4.4.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2016 Practice Test\\QuestionFour\\TestFiles\\S4\\s4.5.in");

    return 0;
}
