#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int push;
struct Coordinate {
    int x;
    int y;
    Coordinate () {}
    Coordinate (int a, int b){
        x = a;
        y = b;
    }
    bool theSame (Coordinate temp){
        if (temp.x == x &&  temp.y == y) return true;
        return false;
    }
};

struct ListItem {
    vector<Coordinate> previousMoves;
};

bool repeated (Coordinate temp, vector<Coordinate> previousMoves){
    for (int i = 0; i < previousMoves.size(); i++)
        if (previousMoves[i].theSame (temp)) return true;
    return false;
}

bool availible (vector <ListItem>& newList, vector<Coordinate> previousMoves, int xChange, int yChange){
    int index = previousMoves.size()-1;
    if (previousMoves[index].x+xChange < 0 || previousMoves[index].y+yChange < 0 ||
        previousMoves[index].x+xChange > 7 || previousMoves[index].y+yChange > 7) return false;
    Coordinate temp (previousMoves[index].x+xChange, previousMoves[index].y+yChange);
    if (!repeated (temp, previousMoves)) {
        ListItem valueHolder;
        valueHolder.previousMoves = previousMoves;
        valueHolder.previousMoves.push_back(temp);
        newList.push_back(valueHolder);
        return true;
    }
    return false;
}

vector<Coordinate> findMoves (vector<Coordinate> moves){
    vector<ListItem> scanList;
    ListItem valueHolder;
    valueHolder.previousMoves = moves;
    scanList.push_back(valueHolder);
    vector<ListItem> newList;
    while (!scanList.empty()){
        for (int i = 0; i < scanList.size(); i++){
            int startSize = scanList[i].previousMoves.size();
            if (availible (newList, scanList[i].previousMoves, 1, 2) && scanList[i].previousMoves.size() == 64)
                return scanList[i].previousMoves;
            if (availible (newList, scanList[i].previousMoves, 2, 2) && scanList[i].previousMoves.size() == 64)
                return scanList[i].previousMoves;
            if (availible (newList, scanList[i].previousMoves, 2,-1) && scanList[i].previousMoves.size() == 64)
                return scanList[i].previousMoves;
            if (availible (newList, scanList[i].previousMoves, 1,-2) && scanList[i].previousMoves.size() == 64)
                return scanList[i].previousMoves;
            if (availible (newList, scanList[i].previousMoves,-1,-2) && scanList[i].previousMoves.size() == 64)
                return scanList[i].previousMoves;
            if (availible (newList, scanList[i].previousMoves,-2,-1) && scanList[i].previousMoves.size() == 64)
                return scanList[i].previousMoves;
            if (availible (newList, scanList[i].previousMoves,-2, 1) && scanList[i].previousMoves.size() == 64)
                return scanList[i].previousMoves;
            if (availible (newList, scanList[i].previousMoves,-1, 2) && scanList[i].previousMoves.size() == 64)
                return scanList[i].previousMoves;
            if (startSize == scanList[i].previousMoves.size()) {
                scanList.erase(scanList.begin()+i);
                i--;
            }
        }
        scanList = newList;
        newList.clear();
    }
    return scanList[0].previousMoves;
}

int main()
{
    Coordinate startingPlace;
    cout << "Enter starting Position ";
    cin >> startingPlace.x >> startingPlace.y;
    startingPlace.x--; startingPlace.y--;
    vector<Coordinate> moves;
    moves.push_back(startingPlace);
    moves = findMoves (moves);
    for (int i = 0 ; i < 8; i++){
        for (int j = 0; j < 8; j++) cout << "(" << moves[i*8+j].x << ", " << moves[i*8+j].y << ") ";
        cout << endl;
    }
    return 0;
}
