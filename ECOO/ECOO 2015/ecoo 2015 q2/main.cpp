#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

using namespace std;

void test (const string& fileName){
    ifstream myFile;
    myFile.open(fileName.c_str());
    for (int i = 0; i < 6; i++){
        char theLine [256];
        int columnWidth;
        myFile.getline(theLine, 256);
        istringstream (theLine) >> columnWidth;
        myFile.getline(theLine, 256);
        string theInput = theLine;
        vector <string> theWords;
        string oneWord = "";
        for (int i = 0; i < theInput.size(); i++){
            if (theInput[i] >= 'a' && theInput[i] <= 'z' || theInput[i] >= 'A' && theInput[i] <= 'Z') oneWord += theInput[i];
            else if (oneWord != "") {
                theWords.push_back(oneWord);
                oneWord = "";
            }
        } theWords.push_back(oneWord);

        string display = "";
        int lineSize = 0;
        for (int i = 0; i < theWords.size(); i++){
            if (theWords[i].length() + lineSize <= columnWidth) {
                display += theWords[i] + " ";
                lineSize += theWords[i].length() + 1;
            }
            else {
                lineSize = 0;
                display += "\n";
                if (theWords[i].length() > columnWidth){
                    string temp = "";
                    for (int j = 0; j < columnWidth; j++) temp+= theWords[i][j];
                    display += temp + " ";
                    lineSize += temp.length() + 1;
                    temp = "";
                    for (int j = columnWidth; j < theWords[i].length(); j++) temp += theWords[i][j];
                    theWords[i] = temp;
                }
                i--;
            }
        }
        display += "\n=====\n";
        cout << display;
    }
    myFile.close();
}

int main()
{
    test ("C:\\Users\\ayuan\\Desktop\\ECOO 2015\\ecoo 2015 q2\\testfile.txt");

    return 0;
}
