#include <iostream>
#include <fstream>
#include <vector>
#include <map>

using namespace std;

struct Coordinate {
    int x;
    int y;
    void setValue (Coordinate a){
        x = a.x;
        y = a.y;
    }
    Coordinate valueOf (int xx, int yy){
        Coordinate temp;
        temp.x = x+xx;
        temp.y = y+yy;
        return temp;
    }
};

int minMoves (Coordinate startPos, Coordinate endPos){
    map <pair<int,int>, bool> wentThere;
    vector<Coordinate> scanList;
    vector<Coordinate> endList;

    scanList.push_back(startPos);
    int moves = 0;

    while (!scanList.empty()){
        Coordinate curPos;
        for (int i = 0; i < scanList.size(); i++){
            curPos.setValue(scanList[i]);
            if (curPos.x < 1 || curPos.x > 8 || curPos.y < 1 || curPos.y > 8 || wentThere[pair<int,int>(curPos.x, curPos.y)]) continue;
            if (curPos.x == endPos.x && curPos.y == endPos.y) return moves;
            wentThere[pair<int,int>(curPos.x, curPos.y)] = true;
            endList.push_back(curPos.valueOf(1,2));
            endList.push_back(curPos.valueOf(2,1));
            endList.push_back(curPos.valueOf(2,-1));
            endList.push_back(curPos.valueOf(1,-2));
            endList.push_back(curPos.valueOf(-1,-2));
            endList.push_back(curPos.valueOf(-2,-1));
            endList.push_back(curPos.valueOf(-2,1));
            endList.push_back(curPos.valueOf(-1,2));
        }
        moves++;
        scanList = endList;
        endList.clear();
    } return -1;
}

void test (const string& fileName){
    ifstream myFile;
    myFile.open(fileName.c_str());

    Coordinate startPos;
    Coordinate endPos;

    myFile >> startPos.x >> startPos.y >> endPos.x >> endPos.y;
    cout << minMoves(startPos, endPos) << endl;
}

int main() {
//    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2010\\TestFiles\\J5\\textFile.txt");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2010\\TestFiles\\J5\\j5.1.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2010\\TestFiles\\J5\\j5.2.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2010\\TestFiles\\J5\\j5.3.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2010\\TestFiles\\J5\\j5.4.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2010\\TestFiles\\J5\\j5.5.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2010\\TestFiles\\J5\\j5.6.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2010\\TestFiles\\J5\\j5.7.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2010\\TestFiles\\J5\\j5.8.in");

    return 0;
}


