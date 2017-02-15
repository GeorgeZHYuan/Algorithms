#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

int triHeight (int mag) {
    int counter = 0;
    while (mag > 0){
        counter++;
        mag -= 2;
    }
    return counter-1;
}

bool inTheTriangle (int mag, int x, int y, int section) {
    int height = triHeight(mag);
    if (section == 1){
        if (y <= mag + height && x > y && x <= mag*2 - (y-mag)) return true;
    }
    else if (section == 2){
        if (y <= mag*2 + height && x > y && x <= mag*3 - (y-mag*2)) return true;
    }
    else if (section == 3){
        if (y <= mag + height && x > mag*3 + (y-mag) && x <= mag*4 - (y-mag)) return true;
    }
    return false;
}

string onOrNot (int mag, int x, int y) {
    if (x > mag && x <= 4*mag && y >= 0){
        if (y <= 1*mag) return "crystal";
        else if (x <= 2*mag) {
            if (inTheTriangle(mag, x, y, 1)) return "crystal";
        }
        else if (x > 2*mag && x <= 3*mag) {
            if (y <= 2*mag) return "crystal";
            else {
                if (inTheTriangle(mag, x, y, 2)) return "crystal";
            }
        }
        else if (x > 3*mag && x <= 4*mag) {
            if (inTheTriangle(mag, x, y, 3)) return "crystal";
        }
    }
    return "empty";
}

void test (const string& fileName) {
    ifstream myFile;
    myFile.open(fileName.c_str());
    int testCases;
    myFile >> testCases;

    int mag, x, y;
    for (int i = 0; i < testCases; i++){
        myFile >> mag >> x >> y;
        int magni = 1;
        for (int i = 0; i < mag-1; i++) magni*= 5;
        cout << onOrNot (magni, x+1, y+1) << endl;
    }
    cout << endl;
    myFile.close();
}

int main()
{
//    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2011 SecondTime\\TestFiles\\s3\\testFile.txt");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2011 SecondTime\\TestFiles\\s3\\s3.1.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2011 SecondTime\\TestFiles\\s3\\s3.2.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2011 SecondTime\\TestFiles\\s3\\s3.3.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2011 SecondTime\\TestFiles\\s3\\s3.4.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2011 SecondTime\\TestFiles\\s3\\s3.5.in");
    return 0;
}
