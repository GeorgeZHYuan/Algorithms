#include <iostream>
#include <string>

using namespace std;

int main()
{
    int lines;
    int sCount;
    int tCount;

    cin >> lines;
    for (int j = 0; j < lines; j++) {
        sCount = 0;
        tCount = 0;

        string theSentence;
        getline(cin, theSentence);

        cout << theSentence << endl;

        for ( int j = 0; i < lines; i++){
            for ( int i = 0; i < theSentence.length(); i++) {
                if (theSentence[i] == "s" || theSentence[i] == "S") {
                    sCount ++;
                }
                else if (theSentence[i] == "t" || theSentence[i] == "T") {
                    tCount ++;
                }
            }
        }

        if (tCount > sCount) {

            cout << "English" << endl;
        }
        else {
            cout << "French" << endl;
        }
    }

    return;
}
