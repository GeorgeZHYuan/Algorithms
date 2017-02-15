#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct Coordinates {
    int x;
    int y;

    Coordinates (){
        x = 0;
        y = 0;
    }
    Coordinates (int _x, int _y){
        x = _x;
        y = _y;
    }

    void setCoordinates (int _x, int _y){
        x = _x;
        y = _y;
    }
    void add (Coordinates amount){
        x += amount.x;
        y += amount.y;
    }
};

int main () {
    Coordinates boundaries;
    cin >> boundaries.x >> boundaries.y;

    vector<Coordinates> destinations;
    Coordinates currentPlace (0,0);
    Coordinates nextMove;

    while (true){
        cin >> nextMove.x >> nextMove.y;
        if (nextMove.x == 0 && nextMove.y == 0) break;
        currentPlace.add(nextMove);
        if (currentPlace.x > boundaries.x) currentPlace.x = boundaries.x;
        if (currentPlace.y > boundaries.y) currentPlace.y = boundaries.y;
        if (currentPlace.x < 0) currentPlace.x = 0;
        if (currentPlace.y < 0) currentPlace.y = 0;

        destinations.push_back(currentPlace);
    }

    for (int i = 0; i < destinations.size(); i++){
        cout << destinations[i].x << " " << destinations[i].y << endl;
    }

    return 0;
}
