#include <iostream>
#include <fstream>
#include <set>

using namespace std;

struct Point {
    set <int> previousPoints;
};

int findNumberOfPathsAddition (int theDestination, Point points []){
    int possiblePaths [theDestination+1];
    for (int i = 0; i < theDestination+1; i++){
        possiblePaths[i] = 0;
    }

    possiblePaths[theDestination] = 1;

    for (int i = theDestination; i >= 0; i--){
        for (set<int>::iterator it = points[i].previousPoints.begin(); it != points[i].previousPoints.end(); it++){
            possiblePaths[*it] += possiblePaths[i];
        }
    }

    return possiblePaths[0];
}

int findNumberOfPathsRecursive (int theDestination, Point points []){
    int numberOfPaths = 0;

    if (theDestination == 0){
        return 1;
    }
    else {
        for (set<int>::iterator it = points[theDestination].previousPoints.begin(); it != points[theDestination].previousPoints.end(); it++){
            numberOfPaths += findNumberOfPathsRecursive(*it , points);
        }
    }

    return numberOfPaths;
}

void test (const string& fileName){
    ifstream myFile;
    myFile.open(fileName.c_str());

    int theDestination;
    myFile >> theDestination;

    int pointOne, pointTwo;
    Point points [theDestination];
    theDestination--;

    while (true){
        Point valueHolder;
        myFile >> pointOne >> pointTwo;
        pointOne--;
        pointTwo--;

        if (pointOne == -1 && pointTwo == -1){
            break;
        }
        points[pointTwo].previousPoints.insert(pointOne);
    }
    myFile.close();

//    cout << findNumberOfPathsRecursive (theDestination, points) << endl; // <------ Recursive takes too much memory and is too slow
    cout << findNumberOfPathsAddition (theDestination, points) << endl;
}

int main() {
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2007\\TestFiles\\s4\\s4.1.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2007\\TestFiles\\s4\\s4.2.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2007\\TestFiles\\s4\\s4.3.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2007\\TestFiles\\s4\\s4.4.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2007\\TestFiles\\s4\\s4.5.in");

    return 0;
}
