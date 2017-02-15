#include <iostream>
#include <fstream>
#include <map>
#include <set>

using namespace std;

int total = 0;
string b [] = {"ookook", "ook", "oogam", "oogum", "ooga","oog", "ugug", "ug", "mookmook", "mook"};
set<string> caveWords (b,b+10);
map <string, int> wordCombinations;

void calculate (string theWord) {
    if (theWord == "") total++;
    else if (wordCombinations.find(theWord) != wordCombinations.end()) total += wordCombinations[theWord];
    else {
        for (int i = 0; i < theWord.length(); i++){
            if (caveWords.find(theWord.substr(0,i+1)) != caveWords.end()){
                calculate(theWord.substr(i+1,theWord.length()));
                if (wordCombinations.find(theWord.substr(i+1,theWord.length())) == wordCombinations.end())
                    wordCombinations.insert(pair<string,int>{theWord.substr(i+1,theWord.length()), total});
            }
        }
    }
}

void test (const string& fileName){
    ifstream myFile;
    myFile.open(fileName.c_str());
    for (int i = 0; i < 10; i++){
        total = 0;
        string theWord;
        myFile >> theWord;
        calculate (theWord);
        cout << total << endl;
    }
    myFile.close();
}

int main()
{
    test ("C:\\Users\\ayuan\\Documents\\Computer\\ECOO\\ECOO 2015\\ecoo 2015 q4\\testFile.txt");
//    test ("C:\\Users\\ayuan\\Documents\\Computer\\ECOO\\ECOO 2015\\ecoo 2015 q4\\DATA41.txt");
    return 0;
}
