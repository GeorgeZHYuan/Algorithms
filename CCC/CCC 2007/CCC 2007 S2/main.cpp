#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Box {
public:
    int width;
    int length;
    int height;

    Box (){}
    Box (int one, int two, int three){
        width = one;
        length = two;
        height = three;
    }
};

void test (const string& fileName){
    ifstream myFile;
    myFile.open(fileName.c_str());

    int numberOfBoxes;
    cin >> numberOfBoxes;



    for (int i = 0; i < numberOfBoxes; i++){

    }


}

int main() {
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2007\\TestFiles\\s2\\s2.1.in");
//    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2007\\TestFiles\\s1\\s1.2.in");
//    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2007\\TestFiles\\s1\\s1.3.in");
//    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2007\\TestFiles\\s1\\s1.4.in");
//    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2007\\TestFiles\\s1\\s1.5.in");

    return 0;
}
