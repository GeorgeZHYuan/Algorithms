#include <iostream>

using namespace std;

class Coordinate {
    public:
        int x;
        int y;

};

bool navigate(Coordinate theCoordinate, char moveDirection, int moveAmount, bool unavailiblePoints[10][8]);
void updateCoordinates (Coordinate *theCoordinate, char moveDirection, int moveAmount);
bool toofar (Coordinate originalCoordinate, Coordinate currentCoordinate);
bool scan (Coordinate theCoordinate, bool movingX, int moveAmount, bool positiveDirection, bool unavailiblePoints [10][8]);

int main()
{
    bool gridPoints [10][8];
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 8; j ++){
            gridPoints [i][j] = false;
        }
    }
    while (true){ // this is the initialization of the invalid points
        gridPoints [1][5] = true;
        gridPoints [1][6] = true;
        gridPoints [1][7] = true;
        gridPoints [2][1] = true;
        gridPoints [2][2] = true;
        gridPoints [2][3] = true;
        gridPoints [2][7] = true;
        gridPoints [3][3] = true;
        gridPoints [3][7] = true;
        gridPoints [4][3] = true;
        gridPoints [4][7] = true;
        gridPoints [5][3] = true;
        gridPoints [5][4] = true;
        gridPoints [5][5] = true;
        gridPoints [5][7] = true;
        gridPoints [6][5] = true;
        gridPoints [6][7] = true;
        gridPoints [7][3] = true;
        gridPoints [7][4] = true;
        gridPoints [7][5] = true;
        gridPoints [7][7] = true;
        gridPoints [8][3] = true;
        gridPoints [8][7] = true;
        gridPoints [9][3] = true;
        gridPoints [9][4] = true;
        gridPoints [9][5] = true;
        gridPoints [9][6] = true;
        gridPoints [9][7] = true;
        break;
    }

    Coordinate originalCoordinate;
    originalCoordinate.x = -1;
    originalCoordinate.y = -5;

    Coordinate currentCoordinate = originalCoordinate;
    char moveDirection;
    int moveAmount;
    bool successful;
    string status;

    while (true){
        cin >> moveDirection >> moveAmount;

        if (moveDirection == 'q'){
            break;
        }

        if (toofar(originalCoordinate, currentCoordinate)){
            status = "DANGER";
            successful = false;
        }
        else {
            successful = navigate(currentCoordinate, moveDirection, moveAmount, gridPoints);
            if (successful){
                status = "safe";
            }
            else {
                status = "DANGER";
            }
        }

        updateCoordinates (&currentCoordinate, moveDirection, moveAmount);
        cout << currentCoordinate.x << " " << currentCoordinate.y << " " << status << endl;

        if (successful == false){
            break;
        }
    }
    return 0;
}

bool navigate(Coordinate theCoordinate, char moveDirection, int moveAmount, bool unavailiblePoints [10][8]){
    if (moveDirection == 'd'){
        return scan(theCoordinate, false, moveAmount, false, unavailiblePoints);
    }
    else if (moveDirection == 'u') {
        return scan(theCoordinate, false, moveAmount, true, unavailiblePoints);
    }
    else if (moveDirection == 'l') {
        return scan(theCoordinate, true, moveAmount, false, unavailiblePoints);
    }
    else if (moveDirection == 'r') {
        return scan(theCoordinate, true, moveAmount, true, unavailiblePoints);
    }
    else {
        cout << "invalid direction input" << endl;
        return false;
    }
}

bool scan (Coordinate theCoordinate, bool movingX, int moveAmount, bool positiveDirection, bool unavailiblePoints [10][8]){
    for (int i = 0; i < moveAmount; i++){
        if (theCoordinate.x >= -1 && theCoordinate.x <= 7 && theCoordinate.y >= -7) {
            if (theCoordinate.y > -2){
                return false;
            }
            if (movingX){
                if (positiveDirection){
                    theCoordinate.x += 1;
                }
                else {
                    theCoordinate.x -= 1;
                }
            }
            else {
                if (positiveDirection){
                    theCoordinate.y += 1;
                }
                else {
                    theCoordinate.y -= 1;
                }
            }

            if (unavailiblePoints [theCoordinate.x + 2][theCoordinate.y *-1] == true){
                return false;
            }
        }
        //cout << theCoordinate.x << " " << theCoordinate.y << endl;
        // cout << theCoordinate.x + 2 << " " << theCoordinate.y *-1 << " " << unavailiblePoints [theCoordinate.x + 2][theCoordinate.y *-1] << endl;
    }
    return true;
}

bool toofar (Coordinate originalCoordinate, Coordinate currentCoordinate){

    if (originalCoordinate.x - currentCoordinate.x > 200 ||
        currentCoordinate.x - originalCoordinate.x > 200 ||
        originalCoordinate.y - currentCoordinate.y > 200 ||
        currentCoordinate.y > -2){
            return true;
    }

    return false;
}

void updateCoordinates (Coordinate *theCoordinate, char moveDirection, int moveAmount){
    if (moveDirection == 'd'){
        theCoordinate -> y -= moveAmount;
    }
    else if (moveDirection == 'u') {
        theCoordinate -> y += moveAmount;
    }
    else if (moveDirection == 'l') {
        theCoordinate -> x -= moveAmount;
    }
    else if (moveDirection == 'r') {
        theCoordinate -> x += moveAmount;
    }
}
