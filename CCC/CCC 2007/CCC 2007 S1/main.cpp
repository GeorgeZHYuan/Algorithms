#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void test (const string& fileName){
    ifstream myFile;
    myFile.open(fileName.c_str());
    vector<string> responses;

    int year;
    int month;
    int day;

    int numberOfPeople;
    myFile >> numberOfPeople;
    for (int i = 0; i < numberOfPeople; i++){
        myFile >> year >> month >> day;
        if (2007 - year == 18){
            if(month < 2){
                responses.push_back("Yes");
            }
            else if (month == 2){
                if (day <= 27){
                    responses.push_back("Yes");
                }
                else {
                    responses.push_back("No");
                }
            }
            else {
                responses.push_back("No");
            }
        }
        else if (2007 - year > 18){
            responses.push_back("Yes");
        }
        else {
            responses.push_back("No");
        }
    }
    myFile.close();
    for (int i = 0; i < responses.size(); i++){
        cout << responses[i] << endl;
    }cout << endl;
}

int main() {
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2007\\TestFiles\\s1\\s1.1.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2007\\TestFiles\\s1\\s1.2.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2007\\TestFiles\\s1\\s1.3.in");

    return 0;
}
