#include <iostream>
#include <fstream>
#include <set>
#include <vector>

using namespace std;

struct ListItem {
    int x;
    int y;
    char value;

    ListItem (int a, int b, char c) {
        x = a;
        y = b;
        value = c;
    }

    void setValue (int a, int b, char c) {
        x = a;
        y = b;
        value = c;
    }
};

void test (const string& fileName) {
    ifstream myFile;
    myFile.open(fileName.c_str());
    set<int> outList;
    vector<ListItem> scanList;
    vector<ListItem> newList;

    int testFiles;
    int xLenght, yLength;

    myFile >> testFiles;
    for (int testCases = 0; testCases < testFiles; testCases++){
        int result = -1;
        scanList.clear(); newList.clear(); outList.clear();

        myFile >> yLength >> xLenght;
        char maze [yLength][xLenght];
        for (int y = 0; y < yLength; y++) {
            for (int x = 0; x < xLenght; x++) {
                myFile >> maze[y][x];
            }
        }

        ListItem valueHolder (0, 0, maze[0][0]);
        scanList.push_back(valueHolder);
        outList.insert(0);

        for (int intersection = 0; intersection < yLength*xLenght; intersection++) {
            for (int i = 0; i < scanList.size(); i++){
                if (validNewLoc (scanList[i], xLenght, yLength, outList))e{

                }

            }
        }



    }

}

int main()
{
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2008\\TestFiles\\s3\\SelfTest.txt");
//    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2008\\TestFiles\\s3\\s3.1.in");
//    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2008\\TestFiles\\s3\\s3.2.in");
//    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2008\\TestFiles\\s3\\s3.3.in");
//    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2008\\TestFiles\\s3\\s3.4.in");
//    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2008\\TestFiles\\s3\\s3.5.in");
    return 0;
}
