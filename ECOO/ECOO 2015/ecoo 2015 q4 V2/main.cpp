#include <iostream>
#include <fstream>
#include <set>

using namespace std;

string words [10] = {"ookook", "ook", "oogam", "oogum", "ooga","oog", "ugug", "ug", "mookmook", "mook"};
set<string> caveWords (words, words+10);

int results (string theWord){
    int outcome [theWord.length()+1];
    outcome[0] = 1;
    for (int i = 1; i <= theWord.length(); i++) outcome[i] = 0;
    for (int i = 2; i <= theWord.length(); i++)
        for (int j = 2; j <= min(8,i); j++)
            if (caveWords.find(theWord.substr(i-j,j)) != caveWords.end()) outcome[i] += outcome[i-j];
    return outcome [theWord.length()];
}

void test (const string& fileName){
    ifstream myFile;
    myFile.open((fileName.c_str()));
    string theWord;
    for (int i = 0; i < 10; i++){
        myFile >> theWord;
        cout << results (theWord) << endl;
    }
    myFile.close();
}

int main()
{
//    test ("C:\\Users\\ayuan\\Documents\\Computer\\ECOO\\ECOO 2015\\ecoo 2015 q4\\testFile.txt");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\ECOO\\ECOO 2015\\ecoo 2015 q4\\DATA41.txt");
    return 0;
}
