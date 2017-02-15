#include <iostream>
#include <fstream>
#include <set>
#include <vector>

using namespace std;

struct ListItem {
    int value;
    int arrayIndex;

    ListItem (int a, int b): value(a), arrayIndex (b) {}
    void setValue (int a, int b) {
        value = a;
        arrayIndex = b;
    }
};

int numberOfPaths (set<int>& nodes, int& mini, int& maxi) {
    int total = 0;

    vector<int> nodeList (nodes.begin(), nodes.end());
    vector<ListItem> scanList;
    vector<ListItem> newList;

    ListItem valueHolder (nodeList[0], 0);
    scanList.push_back(valueHolder);
    newList.push_back(valueHolder);

    while (!newList.empty()) {
        newList.clear();
        for (int i = 0; i < scanList.size(); i++) {
            for (int j = scanList[i].arrayIndex+1; j < nodeList.size(); j++) {
                int difference = nodeList[j] - scanList[i].value;
                if (difference <= maxi) {
                    if (difference >= mini) {
                        if (nodeList[j] == 7000) total++;
                        else {
                            valueHolder.setValue(nodeList[j], j);
                            newList.push_back(valueHolder);
                        }
                    }
                }else break;
            }
        }
        scanList = newList;
    }
    return total;
}

void test (const string& fileName) {
    ifstream myFile;
    myFile.open(fileName.c_str());

    set<int> nodes;{
        nodes.insert(0);
        nodes.insert(990);
        nodes.insert(1010);
        nodes.insert(1970);
        nodes.insert(2030);
        nodes.insert(2940);
        nodes.insert(3060);
        nodes.insert(3930);
        nodes.insert(4060);
        nodes.insert(4970);
        nodes.insert(5030);
        nodes.insert(5990);
        nodes.insert(6010);
        nodes.insert(7000);
    }

    int mini, maxi, newNodes;
    myFile >> mini >> maxi >> newNodes;

    int intHolder;
    for (int i = 0; i < newNodes; i++) {
        myFile >> intHolder;
        nodes.insert(intHolder);
    }

    cout << numberOfPaths (nodes, mini, maxi) << endl;
}

int main()
{
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2007\\TestFiles\\j5\\j5.1.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2007\\TestFiles\\j5\\j5.2.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2007\\TestFiles\\j5\\j5.3.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2007\\TestFiles\\j5\\j5.4.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2007\\TestFiles\\j5\\j5.5.in");
    return 0;
}
