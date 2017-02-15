#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

void test (const string& fileName) {
    ifstream myFile;
    myFile.open(fileName.c_str());
for (int testCases = 0; testCases < 10; testCases++){

    int limit;
    string theLine;
    char input [256];
    myFile.getline(input, 256);
    istringstream (input) >> limit;

    myFile.getline(input, 256);
    theLine = input;

    string result = "";
    int lastPlace = 0;
    vector<string> words;

    for (int i = 0; i < theLine.size(); i++){
        if (theLine[i] == ' '){
            words.push_back(theLine.substr(lastPlace+1,i-lastPlace-1));
            lastPlace = i;
        }
    }
    words.push_back(theLine.substr(lastPlace+1, theLine.size()-lastPlace));
    words[0] = theLine[0] + words[0];

//for (int i = 0; i < words.size(); i++) cout << words[i] << endl;

    int lineSpace = 0;
    for (int i = 0; i < words.size(); i++){
        if (lineSpace + words[i].length() > limit) {
            if (lineSpace == 0) {
                result += words[i].substr(0,limit) + "\n";
                words[i] = words[i].substr(limit, words[i].length() - limit);
            }
            else {
                result += "\n";
            }
            lineSpace = 0;
            i--;
        }
        else {
            result += words[i] + " ";
            lineSpace += words[i].length() + 1;
        }
    }
    result += "\n=====\n";
    cout << result;
}

    myFile.close();

}

int main()
{
//    test ("C:\\Users\\ayuan\\Documents\\Computer\\ECOOCS_2015\\ECOO 2015 Round 1\\Round 1 Data\\DATA20.txt");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\ECOOCS_2015\\ECOO 2015 Round 1\\Round 1 Data\\DATA21.txt");

    return 0;
}
