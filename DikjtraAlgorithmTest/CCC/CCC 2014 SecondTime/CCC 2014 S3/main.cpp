#include <iostream>
#include <fstream>
#include <stack>

using namespace std;

char isInOrder (stack<int>& top){
    stack<int> mid;
    stack<int> bot;

    int nextInLine = 1;
    while (!top.empty()){
//cout << "next in line is : " << nextInLine << endl;
        if (!top.empty() && top.top() == nextInLine){
//cout << "Moved top to bot" << endl;
            bot.push(top.top());
            top.pop();
            nextInLine++;
        }
        else if (!mid.empty() && mid.top() == nextInLine) {
//cout << "Moved mid to bot" << endl;
            bot.push(mid.top());
            mid.pop();
            nextInLine++;
        }
        else if (top.empty() && !mid.empty() && mid.top() != nextInLine){
//cout << "top is empty and mid cannot provide: " << nextInLine << endl;
            return 'N';
        }
        else {
//cout << "Neither top or mid can provide: " << nextInLine << endl;
            if (!top.empty() && !mid.empty() && top.top() > mid.top()) {
//cout << "topNext " << top.top() << " is  bigger than midNext " << mid.top() << endl;
                return 'N';
            }
//cout << "Moved top to mid" << endl;
            mid.push(top.top());
            top.pop();

        }
    }
    return 'Y';
}

void test (const string& fileName) {
    ifstream myFile;
    myFile.open(fileName.c_str());

    int testCases;
    myFile >> testCases;

    for (int i = 0; i < testCases; i++){
        stack<int> top;
        int carts;
        myFile >> carts;
        for (int j = 0; j < carts; j++){
            int cartNumber;
            myFile >> cartNumber;
            top.push(cartNumber);
        }

        cout << isInOrder (top) << " ";
    } cout << endl;

    myFile.close();
}

int main()
{
//    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2014 SecondTime\\TestFiles\\s3\\testFile.txt");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2014 SecondTime\\TestFiles\\s3\\s3.1.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2014 SecondTime\\TestFiles\\s3\\s3.2.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2014 SecondTime\\TestFiles\\s3\\s3.3.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2014 SecondTime\\TestFiles\\s3\\s3.4.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2014 SecondTime\\TestFiles\\s3\\s3.5.in");

    return 0;
}
