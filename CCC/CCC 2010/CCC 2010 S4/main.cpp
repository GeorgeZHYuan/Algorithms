#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;

struct Path {
    int pathStart;
    int pathEnd;
    int pathWeight;
};

struct Node {
    vector<Path> paths;
};

struct ComparePath {
    bool operator () (Path& one, Path& two){
        return one.pathWeight > two.pathWeight;
    }
};

int minimumSpanTreeLength (vector<Node> towns){
    int total [2] = {0, 0};
    for (int k = 0; k < 2; k++){
        priority_queue <Path, vector<Path>, ComparePath> scanList;
        set<int> outList;
        if (k == 1) towns.erase(towns.begin());
        outList.insert(0);
        for (int i = 0; i < towns[0].paths.size(); i++) scanList.push(towns[0].paths[i]);
        while (outList.size() != towns.size()){
            Path temp;
            while (true) {
                temp = scanList.top();
                if (temp.pathEnd > towns.size()) temp.pathEnd = 0;
                scanList.pop();
                int oldSize = outList.size();
                outList.insert(temp.pathEnd);
                if (oldSize < outList.size()) break;
            }
            total[k] += temp.pathWeight;
            if (outList.size() == towns.size()) break;
            for (int j = 0; j < towns[temp.pathEnd].paths.size(); j++){
                    if (outList.find(towns[temp.pathEnd].paths[j].pathEnd) == outList.end())
                    scanList.push(towns[temp.pathEnd].paths[j]);
            }

        }
    }
    return min(total[0], total[1]);
}

void test (const string& fileName){
    ifstream myFile;
    myFile.open(fileName.c_str());

    int numberOfPens;
    myFile >> numberOfPens;

    map<pair<int,int>, int> indexTranslater;
    set<int,int> outList;
    vector<Node> pens;
    vector<Path> paths;

    for (int i = 0; i <= numberOfPens; i++) {
        Node valueHolder;
        pens.push_back(valueHolder);
    }

    for (int i = 1; i <= numberOfPens; i++){
        int numberOfEdges;
        myFile >> numberOfEdges;
        int edges [numberOfEdges];
        int edgeLength [numberOfEdges];
        for (int j = 0; j < numberOfEdges; j++) myFile >> edges [j];
        for (int j = 0; j < numberOfEdges; j++) myFile >> edgeLength [j];

        for (int j = 0; j < numberOfEdges; j++) {
            int first, second;
            if (j != numberOfEdges-1){first = edges[j]; second = edges[j+1];}
            else {first = edges[0]; second = edges[j];}
            if (first > second) {
                int temp = second;
                second = first;
                first = temp;
            }

//cout << "scanning edge: " << first << ", " << second << endl;

            Path valueHolder;
            bool newEdge = true;
            for (map<pair<int,int>,int>::iterator it = indexTranslater.begin(); it != indexTranslater.end(); it++){
                if (it->first == pair<int,int>(first, second)){
                    newEdge = false;
                    paths[indexTranslater[pair<int,int> (first, second)]].pathEnd = i;

//cout << "pen " << paths[indexTranslater[pair<int,int> (first, second)]].pathStart << " is now connected to pen " << paths[indexTranslater[pair<int,int> (first, second)]].pathEnd  << endl;
//cout << "shared edge is: " << first << ", " << second << " and " << (it->first).first << ", " << (it->first).second << endl << endl;
                    break;
                }
            }
            if (newEdge){

                valueHolder.pathStart = i;
                valueHolder.pathEnd = 0;
                valueHolder.pathWeight = edgeLength [j];
                paths.push_back(valueHolder);
                indexTranslater.insert(pair<pair<int,int>, int> (pair<int,int>(first, second), paths.size()-1));

//cout << "pen " << i << " is now connected to path: " << first << ", " << second << endl;
//cout << "pen " << i << " is connected to " << paths[indexTranslater[pair<int,int> (first, second)]].pathEnd << endl << endl;
            }
        }
    }
    myFile.close();

    for (int i = 0; i < paths.size(); i++){
        Path valueHolder;
        valueHolder.pathWeight = paths[i].pathWeight;

        valueHolder.pathEnd = paths[i].pathEnd;
        pens[paths[i].pathStart].paths.push_back(valueHolder);

        valueHolder.pathEnd = paths[i].pathStart;
        pens[paths[i].pathEnd].paths.push_back(valueHolder);
    }

//    for (int i = 0; i < pens.size(); i++){
//        cout << "Path " << i << " connects to: " << endl;
//        for (int j = 0; j < pens[i].paths.size(); j++){
//            cout << pens[i].paths[j].pathEnd << " ";
//        }cout << endl << endl;
//    }

    cout << minimumSpanTreeLength(pens) << endl;
}

int main()
{
//    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2010\\TestFiles\\S4\\selfTest.txt");
//    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2010\\TestFiles\\S4\\s4.1.in");
//    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2010\\TestFiles\\S4\\s4.2.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2010\\TestFiles\\S4\\s4.3.in");
//    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2010\\TestFiles\\S4\\s4.4.in");
//    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2010\\TestFiles\\S4\\s4.5.in");

    return 0;
}
