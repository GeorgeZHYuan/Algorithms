#include <iostream>
#include <fstream>
#include <queue>
#include <cmath>

using namespace std;

struct Coordinate {
    int x;
    int y;
};

float distanceOf(Coordinate one, Coordinate two){
    return sqrt(pow(abs(one.x - two.x),2) + pow(abs(one.y - two.y),2));
}

void test (const string& fileName){
    ifstream myFile;
    myFile.open(fileName.c_str());

    int numberOfRuns;
    myFile >> numberOfRuns;

    Coordinate coordinates [numberOfRuns+1];
    coordinates[numberOfRuns].x = 0;
    coordinates[numberOfRuns].y = 0;
    for (int i = 0; i < numberOfRuns; i++){
        myFile >> coordinates[i].x >> coordinates[i].y;
    }
    myFile.close();

    priority_queue <float> distances;

    for (int i = 0; i < numberOfRuns-1; i++){
        for (int j = i+1; j < numberOfRuns; j++){
            distances.push(distanceOf(coordinates[i], coordinates[j]));
        }
    }
    int sub = distances.size();
    for (int i = 0; i < sub; i++){
        cout << distances.top() << endl;
        distances.pop();
    }
}

int main()
{
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2014\\Test Files\\s5\\test.txt");
//    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2014\\Test Files\\s5\\s5.01.in");
    return 0;
}
