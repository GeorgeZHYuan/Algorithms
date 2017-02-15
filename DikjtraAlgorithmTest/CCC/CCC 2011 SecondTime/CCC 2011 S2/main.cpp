#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void test (const string& fileName) {
    ifstream myFile;
    myFile.open(fileName.c_str());
    int numberOfQuestions;
    char temp;

    myFile >> numberOfQuestions;
    vector<int> answers;
    for (int i = 0; i < numberOfQuestions; i++){
        myFile >> temp;
        answers.push_back(temp);
    }
    int total = 0;
    for (int i = 0; i < numberOfQuestions; i++){
        myFile >> temp;
        if (answers[i] == temp) total++;
    }
    cout << total << endl;
    myFile.close();
}

int main()
{
//    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2011 SecondTime\\TestFiles\\s2\\testFile.txt");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2011 SecondTime\\TestFiles\\s2\\s2.1.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2011 SecondTime\\TestFiles\\s2\\s2.2.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2011 SecondTime\\TestFiles\\s2\\s2.3.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2011 SecondTime\\TestFiles\\s2\\s2.4.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2011 SecondTime\\TestFiles\\s2\\s2.5.in");
    return 0;
}
