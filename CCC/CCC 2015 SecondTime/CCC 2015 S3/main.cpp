#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void test (const string& fileName) {
    ifstream myFile;
    myFile.open(fileName.c_str());

    int portNumber, planeNumber;

    vector<int> ports;
    myFile >> portNumber >> planeNumber;
    for (int i = 0; i <= portNumber; i++) ports.push_back(i);

    int plane;
    int counter = 0;
    for (int i = 0; i < planeNumber; i++){
        myFile >> plane;
        plane;
        if (ports[plane] == 0) break;
        else {
            int desired = ports[ports[plane]];
            for (int j = plane; j >= desired; j--) ports[j]= ports[desired-1];
        }
        counter++;
    }
    cout << counter << endl;

    myFile.close();
}

int main()
{
//    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2015 SecondTime\\TestFiles\\s3\\testFile.txt");
//    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2015 SecondTime\\TestFiles\\s3\\s3.1.in");
//    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2015 SecondTime\\TestFiles\\s3\\s3.2.in");
//    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2015 SecondTime\\TestFiles\\s3\\s3.3.in");
//    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2015 SecondTime\\TestFiles\\s3\\s3.4.in");
//    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2015 SecondTime\\TestFiles\\s3\\s3.5.in");
//    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2015 SecondTime\\TestFiles\\s3\\s3.6.in");
//    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2015 SecondTime\\TestFiles\\s3\\s3.7.in");
//    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2015 SecondTime\\TestFiles\\s3\\s3.8.in");
//    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2015 SecondTime\\TestFiles\\s3\\s3.9.in");
//    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2015 SecondTime\\TestFiles\\s3\\s3.10.in");

    return 0;
}
