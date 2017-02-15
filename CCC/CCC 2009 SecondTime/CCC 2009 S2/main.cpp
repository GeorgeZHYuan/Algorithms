#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

vector< map<string, int> > library;


int possibilities (string board [], int arraySize){
    map<string, int> temp;
    for (int i = 0; i < arraySize; i++) library.push_back(temp);
    for (int i = 0; i < arraySize; i++) (library[i])[board[i]] = 5;

    vector <int> buttonsToPush;
    for (int i = 1; i < arraySize; i++) buttonsToPush.push_back(i);

    return 0;
}

void test (const string& fileName){
    ifstream myFile;
    myFile.open(fileName.c_str());

    int x, y;
    myFile >> y >> x;
    string board [y];

    for (int i = 0; i < y; i++){
        board[i] = "";
        char temp;
        for (int j = 0; j < x; j++){
            myFile >> temp;
            board[i] += temp;
        }
    }
    cout << possibilities (board, y) << endl;
    library.clear();
    myFile.close();
}

int main() {
//    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2009 SecondTime\\TestFiles\\s2\\testFile.txt");
//    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2009 SecondTime\\TestFiles\\s2\\s2.1.in");
//    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2009 SecondTime\\TestFiles\\s2\\s2.2.in");
//    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2009 SecondTime\\TestFiles\\s2\\s2.3.in");
//    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2009 SecondTime\\TestFiles\\s2\\s2.4.in");
//    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2009 SecondTime\\TestFiles\\s2\\s2.5.in");

// This question does not have a correct example. I just skipped this.

    string board [4];
    board [0] = "001";
    board [1] = "011";
    board [2] = "101";
    board [3] = "001";

    int command = 9;
    while (command != 0){
        for (int i = 0; i < 4; i++){
            cout << i+1 << " " << board [i] << endl;
        }
        cout << "next move ";
        cin >> command;
        cout << endl;
        if (command == 100){
            board [0] = "001";
            board [1] = "011";
            board [2] = "101";
            board [3] = "001";
        }

        command--;
        if (command >= 1 && command <= 4){
            for (int i = 0; i < 4; i++){
                if (board[command][i] == board[command-1][i]) board[command][i] = '0';
                else board[command][i] = '1';
            }
        }
    }

    return 0;
}


