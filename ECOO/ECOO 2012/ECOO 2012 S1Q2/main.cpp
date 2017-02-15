#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

int matchedLength (string& theCode, string terminatorHead, int index){
    int lengthReached = 1;
    for (int i = index+1; i < theCode.size(); i++){
        if (i-(index+1) > terminatorHead.size()) break;
        if (theCode[i] == terminatorHead[i-(index+1)]) lengthReached++;
        else break;
    }
    return lengthReached;
}

void makeMatch(string& theCode, int indexStart, int indexEnd, string& temp){
    temp = "";
    for (int i = indexEnd; i >= indexStart+1; i--){
        if (theCode[i] == 'A') temp += 'T';
        else if (theCode[i] == 'T') temp += 'A';
        else if (theCode[i] == 'C') temp += 'G';
        else if (theCode[i] == 'G') temp += 'C';
    }
}

void test (const string& fileName) {
    ifstream myFile;
    myFile.open(fileName.c_str());
    for (int n = 0; n < 5; n++){
        string theCode;
        string promoter = "TATAAT";
        myFile >> theCode;

        int indexStart = 0;
        string temp;

        // locating promoter
        for (indexStart; indexStart < theCode.length(); indexStart++){
            if (theCode[indexStart] == 'T'){
                temp = "";
                for (int i = indexStart; i <= indexStart+5; i++) temp += theCode[i];
                if (temp == promoter) {
                    break;
                }
            }
        } indexStart += 10;

        // finding gene
        int indexEnd = indexStart + 6;
        string spare;
        bool endIt = false;

        for (indexEnd; indexEnd <= theCode.size()-6; indexEnd++){
            makeMatch(theCode, indexStart+1 ,indexEnd, temp);
            for (int i = indexEnd+1; i < theCode.size(); i++){
                if (theCode[i] == temp[0]){
                    int matched = matchedLength (theCode, temp, i);
                    if (matched >= 6) {
                        indexEnd -= matched;
                        endIt = true;
                        break;
                    }
                }
            }
            if (endIt) break;
        }

        cout << n+1 << ": ";
        for (int i = indexStart; i <= indexEnd; i++){
            if (theCode[i] == 'A') cout << "U";
            else if (theCode[i] == 'T') cout << "A";
            else if (theCode[i] == 'G') cout << "C";
            else if (theCode[i] == 'C') cout << "G";
        } cout << endl;
    }
    myFile.close ();
}

int main()
{
    test ("C:\\Users\\ayuan\\Documents\\Computer\\ECOO\\ECOO 2012\\ECOO-CS Competition 2012\\Round 1\\Round 1\\data\\DATA21.txt");
//    test ("C:\\Users\\ayuan\\Documents\\Computer\\ECOO\\ECOO 2012\\ECOO-CS Competition 2012\\Round 1\\Round 1\\data\\DATA22.txt");

    return 0;
}
