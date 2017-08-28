#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

struct Path {
    int pathEnd;
    int pathWeigth;
};

struct Node {
    vector<Path> paths;
};

struct ComparePath {
    bool operator () (Path& one, Path& two){
        return one.pathWeigth > two.pathWeigth;
    }
};

int minimumSpanTreeLength (vector<Node>& towns){
    int total = 0;
    priority_queue <Path, vector<Path>, ComparePath> scanList;
    set<int> outList;
    outList.insert(0);
    for (int i = 0; i < towns[0].paths.size(); i++) scanList.push(towns[0].paths[i]);
    while (outList.size() != towns.size()){
        Path temp;
        while (true) {
            temp = scanList.top();
            scanList.pop();
            int oldSize = outList.size();
            outList.insert(temp.pathEnd);
            if (oldSize < outList.size()) break;
        }
        total += temp.pathWeigth;
        for (int i = 0; i < towns[temp.pathEnd].paths.size(); i++)
            if (outList.find(towns[temp.pathEnd].paths[i].pathEnd) == outList.end())
                scanList.push(towns[temp.pathEnd].paths[i]);
    }
    return total;
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
        temp.pathWeigth = pathLength;
        temp.pathEnd = townTwo;
        towns[townOne].paths.push_back(temp);
        temp.pathEnd = townOne;
        towns[townTwo].paths.push_back(temp);
    }
    myFile.close();
    cout << minimumSpanTreeLength (towns) << endl;
}

int main() {

    test("C:\\Users\\ayuan\\Desktop\\PrimAlgorithmTest\\TestFiles\\case1.txt");
    return 0;
}
