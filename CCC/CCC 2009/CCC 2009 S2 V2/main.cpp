#include <iostream>
#include <stdlib.h>
#include <vector>

// this will output all possibilities of the light board instead of the bottom row;

using namespace std;

class LightBoard {
    public:
        bool board [29][7];
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

        bool hasSameBottomRow (LightBoard theLightBoard){
            for (int j = 0; j < theLightBoard.columns; j++){
                if (board[0][j] != theLightBoard.board[0][j]){
                    return false;
                }
            }
            return true;
        }
};

int numberOfLightPatterns (LightBoard lightBoard, int rows, int columns);
void pushButton (int buttonRow, LightBoard&);
bool alreadyExists (LightBoard theItem, vector<LightBoard>&);
int findBottoms (vector<LightBoard>&);

int main(){
    int rows;
    int columns;
    int sub;

    cin >> rows >> columns;
    LightBoard lightBoard (rows, columns);

    for (int i = (rows - 1); i > -1 ; i--){
        for (int j = 0; j < columns; j++){

            cin >> sub;
            if (sub == 1){
                lightBoard.board [i][j] = true;
            }
            else {
                lightBoard.board [i][j] = false;
            }
        }
    }

    cout << endl << numberOfLightPatterns (lightBoard, rows, columns) << endl;

    return 0;
}

int numberOfLightPatterns (LightBoard originalBoard, int rows, int columns){
    vector<LightBoard> lightBoardList;
    lightBoardList.push_back(originalBoard);

    LightBoard tester (rows, columns);
    int lastSize = 0;
    int newBoards = 0;
    for (int j = 0; j < lightBoardList.size(); j++){
        for (int i = 0; i < originalBoard.rows - 1; i++){
            tester.setBoard(lightBoardList[j]);
            pushButton(i, tester);
            if (!alreadyExists(tester, lightBoardList)){
                lightBoardList.push_back(tester);
            }
        }
    }
    /*
    for (int a = 0; a < lightBoardList.size(); a++){
        cout << endl;
        for (int i = (lightBoardList[a].rows - 1); i > -1 ; i--){
            for (int j = 0; j < lightBoardList[a].columns; j++){
                cout << lightBoardList[a].board [i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    */
    //return lightBoardList.size();
    return findBottoms(lightBoardList);
}

int findBottoms (vector<LightBoard>& lightBoardList){
    vector<LightBoard> newList;
    newList.push_back(lightBoardList[0]);
    bool noRepeats;

    for (int i = 0; i < lightBoardList.size(); i++){
        noRepeats = true;
        for (int j = 0; j < newList.size(); j++){
            if (lightBoardList[i].hasSameBottomRow(newList[j])){
                noRepeats = false;
            }
        }
        if (noRepeats){
            newList.push_back(lightBoardList[i]);
        }
    }

    return newList.size();
}

void pushButton (int buttonRow, LightBoard& theBoard){
    if (buttonRow < theBoard.rows && buttonRow >= 0){
        /*cout << endl;
        for (int i = (theBoard.rows - 1); i > -1 ; i--){
            for (int j = 0; j < theBoard.columns; j++){
                cout << theBoard.board [i][j];
            }
            cout << endl;
        }
        cout << endl;
        */for (int i = 0; i < theBoard.columns; i++){
            if (theBoard.board[buttonRow][i] == theBoard.board[buttonRow+1][i]){
                theBoard.board[buttonRow][i] = false;
            }
            else {
                theBoard.board[buttonRow][i] = true;
            }
        }
        /*for (int i = (theBoard.rows - 1); i > -1 ; i--){
            for (int j = 0; j < theBoard.columns; j++){
                cout << theBoard.board [i][j];
            }
            cout << endl;
        }
        cout << endl;*/
    }
}

bool alreadyExists (LightBoard theItem, vector<LightBoard>& theList){
    if (theList.empty()){
        return false;
    }
    for (int i = 0; i < theList.size(); i++){
        if (theList[i].isTheSame(theItem)){
            return true;
        }
    }
    return false;
}
