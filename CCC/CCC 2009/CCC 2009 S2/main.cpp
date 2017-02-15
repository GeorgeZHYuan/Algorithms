#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

class LightBoard {
    public:
        bool board [30][8];
        int rows;
        int columns;

        LightBoard (int _rows, int _columns){
            rows = _rows;
            columns = _columns;
        }

        void setBoard (LightBoard theLightBoard){
            rows = theLightBoard.rows;
            columns = theLightBoard.columns;

            for (int i = 0; i < theLightBoard.rows; i++){
                for (int j = 0; j < theLightBoard.columns; j++){
                    board[i][j] = theLightBoard.board[i][j];
                }
            }
        }

        bool isTheSame (LightBoard theLightBoard){
            if (theLightBoard.rows != rows || theLightBoard.columns != columns ){
                return false;
            }
            for (int i = 0; i < theLightBoard.rows; i++){
                for (int j = 0; j < theLightBoard.columns; j++){
                    if (board[i][j] != theLightBoard.board[i][j]){
                        return false;
                    }
                }
            }
            return true;
        }

};

int numberOfLightPatterns (LightBoard lightBoard, int rows, int columns);
void pushButton (int buttonRow, LightBoard&);
bool alreadyExists (LightBoard theItem, vector<LightBoard>&);

int main()
{
    int rows;
    int columns;

    cin >> rows >> columns;
    LightBoard lightBoard (rows, columns);

    for (int i = (rows - 1); i > -1 ; i--){
        for (int j = 0; j < columns; j++){
            cin >> lightBoard.board [i][j];
        }
    }

    cout << numberOfLightPatterns (lightBoard, rows, columns) << endl;

    return 0;
}

int numberOfLightPatterns (LightBoard originalBoard, int rows, int columns){
    vector<LightBoard> lightBoardList;
    lightBoardList.push_back(originalBoard);

    LightBoard tester (rows, columns);
    int lastSize = 0;
    while (lightBoardList.size() != lastSize){
        lastSize = lightBoardList.size();
        for (int i = 0; i < originalBoard.rows; i++){
            tester.setBoard(lightBoardList[i]);
            pushButton(i, tester);
            if (!alreadyExists(tester, lightBoardList)){
                lightBoardList.push_back(tester);
            }
        }
    }

    return lightBoardList.size();
}

void pushButton (int buttonRow, LightBoard& theBoard){
    if (buttonRow < theBoard.rows && buttonRow >= 0){
        for (int i = 0; i < theBoard.columns; i++){
            if (theBoard.board[buttonRow][i] == theBoard.board[buttonRow+1][i]){
                theBoard.board[buttonRow][i] = false;
            }
            else {
                theBoard.board[buttonRow][i] = true;
            }
        }
    }
}

bool alreadyExists (LightBoard theItem, vector<LightBoard>& theList){
    if (theList.empty()){
        return true;
    }
    for (int i = 0; i < theList.size(); i++){
        if (theList[i].isTheSame(theItem)){
            return true;
        }
    }
    return false;
}
