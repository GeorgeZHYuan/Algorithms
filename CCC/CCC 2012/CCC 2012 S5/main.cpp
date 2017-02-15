#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct Coordinate {
    int x;
    int y;

    Coordinate(){}
    Coordinate (int a, int b){
        x = a;
        y = b;
    }
    void setCoordinates (int a, int b){
        x = a;
        y = b;
    }
};

bool spaceIsAvailible (int x, int y, vector<Coordinate>& catCages){
    for (int i = 0; i < catCages.size(); i++) if (catCages[i].x == x && catCages[i].y == y) return false;
    return true;
}

int numberOfMoves (Coordinate destination, vector<Coordinate>& catCages){
    int cages [destination.y+1][destination.x+1];
    for (int y = 0; y <= destination.y; y++){
        for (int x = 0; x <= destination.x; x++){
            if (x == 0 && y == 0) cages [0][0] = 1;
            else if (spaceIsAvailible(x, y, catCages)){
                if (x == 0) cages [y][x] = cages[y-1][x];
                else if (y == 0) cages [y][x] = cages[y][x-1];
                else cages[y][x] = (cages[y-1][x] + cages[y][x-1]);
            }
            else cages [y][x] = 0;
        }
    }
    return cages[destination.y][destination.x];
}

void test (const string& fileName){
    Coordinate destination;
    cin >> destination.x >> destination.y;
    destination.x--; destination.y--;
    int numberOfCats;
    cin >> numberOfCats;
    vector<Coordinate> catCages;
    Coordinate valueHolder;
    for (int i = 0; i < numberOfCats; i++){
        cin >> valueHolder.x >> valueHolder.y;
        valueHolder.x--; valueHolder.y--;
        catCages.push_back(valueHolder);
    }
    cout << numberOfMoves (destination, catCages) << endl;
}
