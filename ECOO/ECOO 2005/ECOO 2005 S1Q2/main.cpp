#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

void test (const string& fileName){
    ifstream myFile;
    myFile.open(fileName.c_str());

    for (int testCases = 0; testCases < 5; testCases++){
        char subInput [256];
        string theInput;
        myFile.getline(subInput, 256);
        theInput = subInput;

        vector<string> theOutput;
        int xLoc = 0;
        int yLoc = 0;

        string substituteString;
        for (int i = 0; i < theInput.size(); i++){
//cout << "we're now at i: " << i << " with value " << theInput[i] << " with new loop" << endl;
            // Calibrating the Grid
            if (yLoc >= theOutput.size()){
                substituteString = "";
                int paddingNeeded = yLoc - theOutput.size() + 1;
                for (int j = 0; j < paddingNeeded; j++){
                    theOutput.push_back(substituteString);
                }
            }
            if (yLoc < 0){
                substituteString = "";
                int paddingNeeded = 0 - yLoc;
                for (int j = 0; j < paddingNeeded; j++){
                    theOutput.insert(theOutput.begin(), substituteString);
                }
            }
            if (xLoc < 0){

//cout << "At " << i << ": " << theInput[i] << " ";
//cout << "xLoc is: " << xLoc << " at yLoc " << yLoc << " and the row length is currently: " << theOutput[yLoc].length() << endl;

                substituteString = "";
                int paddingNeeded = 0 - xLoc;

//cout << "padding given is: " << paddingNeeded << endl;

                for (int j = 0; j < paddingNeeded; j++){
                    substituteString += " ";
                }
                for (int j = 0; j < theOutput.size(); j++){
                    theOutput[j].insert(0, substituteString);
                }
                xLoc = 0;
            }
            if (xLoc > theOutput[yLoc].length()){
//cout << "At " << i << ": " << theInput[i] << " ";
//cout << "xLoc is: " << xLoc << " at yLoc " << yLoc << " and the row length is currently: " << theOutput[yLoc].length() << endl;

                substituteString = "";
                int paddingNeeded = xLoc - theOutput[yLoc].length();

//cout << "padding given is: " << paddingNeeded << endl;

                for (int j = 0; j < paddingNeeded; j++){
                    substituteString += " ";
                }
                theOutput[yLoc].insert(0, substituteString);
            } // End of Calibrating Grid

            if (theInput[i] == '?'){
//cout << "Printing out: " << theInput [i+1] << endl;
                i++;
                substituteString = theInput[i];
                theOutput[yLoc].insert(xLoc, substituteString);
                xLoc++;
            }

            else if (theInput[i] == '<'){
//cout << "found function: ";
                i++;
                string buffer = "";
                int shiftAmount;
                if (theInput[i] == 'D'){
//cout << "D" << endl;
                    i++;
                    while (theInput[i] != '>'){
                        buffer += theInput[i];
                        i++;
                    }
                    istringstream (buffer) >> shiftAmount;
                    yLoc += shiftAmount;
                }
                else if (theInput[i] == 'U'){
//cout << "U" << endl;
                    i++;
                    while (theInput[i] != '>'){
                        buffer += theInput[i];
                        i++;
                    }
                    istringstream (buffer) >> shiftAmount;
                    yLoc -= shiftAmount;
                }
                else if (theInput[i] == 'L'){
//cout << "L" << endl;
                    i++;
                    while (theInput[i] != '>'){
                        buffer += theInput[i];
                        i++;
                    }
                    istringstream (buffer) >> shiftAmount;
                    xLoc -= shiftAmount;
                }
                else if (theInput[i] == 'R'){
//cout << "R" << endl;
                    i++;
                    while (theInput[i] != '>'){
                        buffer += theInput[i];
                        i++;
                    }
                    istringstream (buffer) >> shiftAmount;
                    xLoc += shiftAmount;
                }
            }

            else {
                if (theInput[i+2] != 'M'){
//cout << "printing out: " << theInput[i] << endl;
                    substituteString = theInput[i];
                    theOutput[yLoc].insert(xLoc, substituteString);
                    xLoc++;
                }
                else {
//cout << "found function M" << endl;
                    char repeatedChar = theInput[i];
                    i+=3;
                    int copyAmount;
                    string buffer = "";
                    while (theInput[i] != '>'){
                        buffer += theInput[i];
                        i++;
                    }
                    istringstream (buffer) >> copyAmount;
                    substituteString = "";
                    for (int j = 0; j < copyAmount; j++){
                        substituteString += repeatedChar;
                    }
//cout << "inserted string: '" << substituteString << "'" << endl;
                    theOutput[yLoc].insert(xLoc, substituteString);
                    xLoc+= substituteString.length();
                }
            }
        }
        for (int i = 0; i < theOutput.size(); i++){
            cout << theOutput[i] << endl;
        }
        cout << endl << endl;
    }
    myFile.close();
}

int main()
{
    test ("C:\\Users\\ayuan\\Documents\\Computer\\ECOO\\ECOO 2005\\TEST21.txt");
    return 0;
}
