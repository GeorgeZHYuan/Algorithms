#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int> > graph;

int separation (int a, int b) {
    map<int, int> scanned;
    queue<pair<int, int> > scanList;
    scanList.push(pair<int, int>(a, 0));
    scanned[a] = 5;

    while (!scanList.empty()){
        if (scanList.front().first == b) return scanList.front().second;
        for (int i = 0; i < graph[scanList.front().first].size(); i++){
            if (scanned.count(graph[scanList.front().first][i]) == 0) {
                scanned[graph[scanList.front().first][i]] = 5;
                scanList.push(pair<int, int> (graph[scanList.front().first][i], scanList.front().second+1));
            }
        }
        scanList.pop();
    }
    return -1;
}

void test (const string& fileName) {
    ifstream myFile;
    myFile.open(fileName.c_str());

    graph.clear();
    vector<int> temp;
    for (int i = 0; i < 9999; i++) graph.push_back(temp);

    int studentNumber;
    int a, b;

    myFile >> studentNumber;
    for (int i = 0; i < studentNumber; i++){
        myFile >> a >> b;
        a--; b--;
        graph[a].push_back(b);
    }

    while (true){
        myFile >> a >> b;
        a--; b--;
        if (a == -1 && b == -1) break;
        else {
            int result = separation (a, b);
            if (result == -1) cout << "No" << endl;
            else cout << "Yes " << result-1 << endl;
        }
    }

    myFile.close();
}

int main()
{
//    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2007 SecondTime\\TestFiles\\s3\\testFile.txt");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2007 SecondTime\\TestFiles\\s3\\s3.1.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2007 SecondTime\\TestFiles\\s3\\s3.2.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2007 SecondTime\\TestFiles\\s3\\s3.3.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2007 SecondTime\\TestFiles\\s3\\s3.4.in");

    return 0;
}
