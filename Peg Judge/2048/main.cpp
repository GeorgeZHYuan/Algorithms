#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

void copyBoard (int (&reciever)[4][4], int original [4][4]) {
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            reciever[i][j] = original[i][j];
        }
    }
};

struct ListItem {
    char lastMove;
    int consecutiveFails;
    int board [4][4];

    ListItem (){};
    ListItem (char a, int b, int theBoard[4][4]){
        lastMove = 'a';
        consecutiveFails = b;
        copyBoard(board, theBoard);
    }
    void setValue (char a, int b, int theBoard[4][4]){
        lastMove = 'a';
        consecutiveFails = b;
        copyBoard(board, theBoard);
    }

};

void swipe (int (&theBoard)[4][4], char direction, int (&response)) {
    response = -1;
    if (direction == 'u'){
        for (int j = 0; j < 4; j++) {
            for (int i = 1; i < 4; i++) {
//cout << "at " << j+1 << "," << i+1 << endl;
                if (theBoard[i][j] == 0) {
//cout << j+1 << "," << i+1 << " is 0. skipping this y" << endl << endl;
                    continue;
                }
                int curI = i;
//cout << j+1 << "," << i+1 << " is " << theBoard[i][j] << " commencing move" << endl;
                while (curI > 0){
                    if (theBoard[curI][j] == 0) {
//cout << j+1 << "," << curI+1 << " is 0" << endl;
                        curI--;
                    }
                    else if (theBoard[curI-1][j] == 0) {
//cout << "moved number: " << theBoard[curI][j] << " down one place" << endl;
                        theBoard[curI-1][j] = theBoard[curI][j];
                        theBoard[curI][j] = 0;
                        response = max(0, response);
                        curI--;
                    }
                    else if (theBoard[curI-1][j] == theBoard[curI][j]) {
//cout << "combined numbers: " << theBoard[curI][j] << " " << theBoard[curI-1][j] << endl;
                        theBoard[curI-1][j] += theBoard[curI][j];
                        theBoard[curI][j] = 0;
                        response = max(theBoard[curI-1][j], response);
                        break;
                    }
                    else {
//cout << "coordinate: " << j+1 << ", " << curI-1 << " is invalid" << endl;
                        break;
                    }
                }
            }
        }
    }
    else if (direction == 'd'){
        for (int j = 0; j < 4; j++) {
            for (int i = 3; i >=0 ; i--) {
//cout << "at " << j+1 << "," << i+1 << endl;
                if (theBoard[i][j] == 0) {
//cout << j+1 << "," << i+1 << " is 0. skipping this y" << endl << endl;
                    continue;
                }
                int curI = i;
//cout << j+1 << "," << i+1 << " is " << theBoard[i][j] << " commencing move" << endl;
                while (curI < 3){
                    if (theBoard[curI][j] == 0) {
//cout << j+1 << "," << curI+1 << " is 0" << endl;
                        curI++;
                    }
                    else if (theBoard[curI+1][j] == 0) {
//cout << "moved number: " << theBoard[curI][j] << " down one place" << endl;
                        theBoard[curI+1][j] = theBoard[curI][j];
                        theBoard[curI][j] = 0;
                        response = max(0, response);
                        curI++;
                    }
                    else if (theBoard[curI+1][j] == theBoard[curI][j]) {
//cout << "combined numbers: " << theBoard[curI][j] << " " << theBoard[curI-1][j] << endl;
                        theBoard[curI+1][j] += theBoard[curI][j];
                        theBoard[curI][j] = 0;
                        response = max(theBoard[curI+1][j], response);
                        break;
                    }
                    else {
//cout << "coordinate: " << j+1 << ", " << curI-1 << " is invalid" << endl;
                        break;
                    }
                }
            }
        }
    }
    else if (direction == 'r'){
        for (int i = 0; i < 4; i++) {
            for (int j = 3; j >=0; j--) {
//cout << "at " << j+1 << "," << i+1 << endl;
                if (theBoard[i][j] == 0) {
//cout << j+1 << "," << i+1 << " is 0. skipping this y" << endl << endl;
                    continue;
                }
                int curJ = j;
//cout << j+1 << "," << i+1 << " is " << theBoard[i][j] << " commencing move" << endl;
                while (curJ < 3){
                    if (theBoard[i][curJ] == 0) {
//cout << j+1 << "," << curI+1 << " is 0" << endl;
                        curJ++;
                    }
                    else if (theBoard[i][curJ+1] == 0) {
//cout << "moved number: " << theBoard[curI][j] << " down one place" << endl;
                        theBoard[i][curJ+1] = theBoard[i][curJ];
                        theBoard[i][curJ] = 0;
                        response = max(0, response);
                        curJ++;
                    }
                    else if (theBoard[i][curJ+1] == theBoard[i][curJ]) {
//cout << "combined numbers: " << theBoard[curI][j] << " " << theBoard[curI-1][j] << endl;
                        theBoard[i][curJ+1] += theBoard[i][curJ];
                        theBoard[i][curJ] = 0;
                        response = max(theBoard[i][curJ+1], response);
                        break;
                    }
                    else {
//cout << "coordinate: " << j+1 << ", " << curI-1 << " is invalid" << endl;
                        break;
                    }
                }
            }
        }
    }
    else if (direction == 'l'){
        for (int i = 0; i < 4; i++) {
            for (int j = 1; j < 4; j++) {
//cout << "at " << j+1 << "," << i+1  << " value: " << theBoard[i][j]  << endl;
                if (theBoard[i][j] == 0) {
//cout << j+1 << "," << i+1 << " is 0. skipping this y" << endl << endl;
                    continue;
                }
                int curJ = j;
//cout << j+1 << "," << i+1 << " is " << theBoard[i][j] << " commencing move" << endl;
                while (curJ > 0){
                    if (theBoard[i][curJ] == 0) {
//cout << j+1 << "," << curJ+1 << " is 0" << endl;
                        curJ--;
                    }
                    else if (theBoard[i][curJ-1] == 0) {
//cout << "moved number: " << theBoard[i][curJ] << " down one place" << endl;
                        theBoard[i][curJ-1] = theBoard[i][curJ];
                        theBoard[i][curJ] = 0;
                        response = max(0, response);
                        curJ--;
                    }
                    else if (theBoard[i][curJ-1] == theBoard[i][curJ]) {
//cout << "combined numbers: " << theBoard[i][curJ] << " " << theBoard[i][curJ-1] << endl;
                        theBoard[i][curJ-1] += theBoard[i][curJ];
                        theBoard[i][curJ] = 0;
                        response = max(theBoard[i][curJ-1], response);
                        break;
                    }
                    else {
//cout << "cant do anything with coordinate: " << j+1 << ", " << curJ-1 << " value: " << theBoard[i][curJ-1] <<  endl;
                        break;
                    }
                }
            }
        }
    }
};

int findBestValue (int theBoard [4][4]) {
    int values [13] = {0 ,2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096};
    int maxValue = 0;
    int bestValue = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            bestValue = max(bestValue, theBoard[i][j]);
            maxValue += theBoard[i][j];
        }
    }
    for (int i = 1; i < 13; i++) {
        if (maxValue < values[i]) {
            maxValue = values[i-1];
            break;
        }
    }

    vector<ListItem> scanList;
    vector<ListItem> newList;
    ListItem temp ('n', 0, theBoard);
    scanList.push_back(temp);


    while(!scanList.empty()){
        for (int i = 0; i < scanList.size(); i++){
            char nextMoves [4] = {'u', 'd', 'l', 'r'};
            if (scanList[i].consecutiveFails > 3) continue;
            if (scanList[i].lastMove == 'u' || scanList[i].lastMove == 'd'){
                nextMoves[0] = 'n';
                nextMoves[1] = 'n';
            } else if (scanList[i].lastMove == 'l' || scanList[i].lastMove == 'r'){
                nextMoves[2] = 'n';
                nextMoves[3] = 'n';
            }

            for (int j = 0; j < 4; j++){
                if (nextMoves[j] != 'n') {
                    int response;
                    int tempBoard [4][4];
                    copyBoard (tempBoard, scanList[i].board);
                    swipe(tempBoard, nextMoves[j], response);
                    int status = scanList[i].consecutiveFails + 1;

                    if (response > -1) {
                        if (response == maxValue) return response;
                        else if (response > 0) {
                            status = 0;
                            bestValue = max (bestValue, response);
                        }
                        temp.setValue (nextMoves[j], status, tempBoard);
                        newList.push_back(temp);
                    }


                }
            }
        }

        scanList = newList;
        newList.clear();
    }

    return bestValue;
}

int main() {
    for (int testCases = 0; testCases < 5; testCases++) {
        int originalBoard [4][4];
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                cin >> originalBoard [i][j];
            }
        }

        cout << findBestValue(originalBoard) << endl;

    }
    return 0;
}
