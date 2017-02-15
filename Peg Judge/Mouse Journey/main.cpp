#include <iostream>

using namespace std;


int main (){
    int x, y;
    cin >> x >> y;

    int board [x][y];
    int testCases;

    cin >> testCases;
    int x2, y2;

    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            board[i][j] = -1;
        }
    }

    for (int i = 0; i < testCases; i++) {
        cin >> x2 >> y2;
        board [x2-1][y2-1] = 0;
    }

    board [0][0] = 1;

    for (int i = 1; i < x; i++) {
        if (board[i][0] != 0) board[i][0] = board[i-1][0];
    }

    for (int i = 1; i < y; i++) {
        if (board[0][i] != 0) board[0][i] = board[0][i-1];
    }

    for (int i = 1; i < x; i++) {
        for (int j = 1; j < y; j++) {
            if (board[i][j] != 0) board[i][j] = board[i-1][j] + board[i][j-1];
        }
    }
    cout << board[x-1][y-1] << endl;

    return 0;
}

