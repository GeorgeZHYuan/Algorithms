#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <set>

using namespace std;

class Path {
    public:
        int pathEnd;
        int pathLength;

        Path (){}
        Path (int destination, int _length){
            pathEnd = destination;
            pathLength = _length;
        }

        void setPath(int destination, int _length){
            pathEnd = destination;
            pathLength = _length;
        }
};
class Town {
    public:
        int cost = -1;
        vector<Path> paths;
};
class ListItem {
    public:
        int indexOfTown;
        int totalCost;

        ListItem () {}
        ListItem (int _indexOfTown, int _totalCost){
            indexOfTown = _indexOfTown;
            totalCost = _totalCost;
        }

        void setValue (int _indexOfTown, int _totalCost){
            indexOfTown = _indexOfTown;
            totalCost = _totalCost;
        }
};

void setPath (int ID1, int ID2, Town&, Town&, int pathLength);
int findShortestPath (int destinationIndex, Town towns [], int numberOfTowns);
int partOfTheList (int townIndex, vector<ListItem>&);

void test (const string& fileName){
    ifstream myFile;
    myFile.open(fileName.c_str());

    long spareInt [4];

    int numberOfTowns;
    myFile >> numberOfTowns;
    Town towns [numberOfTowns];

    myFile >> spareInt[3];

    for (int i = 0; i < spareInt[3]; i++){
        myFile >> spareInt[0] >> spareInt[1] >> spareInt [2];
        spareInt[0]--;
        spareInt[1]--;
        setPath(spareInt[0], spareInt[1], towns[spareInt[0]], towns[spareInt[1]], spareInt[2]);
    }

    myFile >> spareInt[2];
    for (int i = 0; i < spareInt[2]; i++){
        myFile >> spareInt[0] >> spareInt[1];
        towns [spareInt[0] - 1].cost = spareInt[1];
    }

    myFile >> spareInt[0];
    myFile.close();

   cout << findShortestPath (spareInt[0] - 1, towns, numberOfTowns) << endl << endl;
}

int main(){
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2009\\TestFiles\\s4\\s4.1.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2009\\TestFiles\\s4\\s4.2.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2009\\TestFiles\\s4\\s4.3.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2009\\TestFiles\\s4\\s4.4.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2009\\TestFiles\\s4\\s4.5.in");

    return 0;
}

int findShortestPath (int destinationIndex, Town towns [], int numberOfTowns){
    bool isAvailable [numberOfTowns];
    for (int i = 0; i <numberOfTowns; i++){
        isAvailable[i] = true;
    }
    ListItem valueHolder (destinationIndex, 0);
    int minCost = 9999999;
    vector<ListItem> observationList;
    observationList.push_back(valueHolder);
    int obs_ListIndex = 0;
    int arrayIndex = observationList[obs_ListIndex].indexOfTown;

    while (observationList.size() > 0){
        // newMin
        isAvailable [arrayIndex] = false;
        arrayIndex = observationList[obs_ListIndex].indexOfTown;
        if (towns[arrayIndex].cost > -1 && minCost > towns[arrayIndex].cost + observationList[obs_ListIndex].totalCost){
            minCost = (towns[arrayIndex].cost + observationList[obs_ListIndex].totalCost);
        }

        // travel
        for (int i = 0; i < towns[arrayIndex].paths.size(); i++){
            if (isAvailable[towns[arrayIndex].paths[i].pathEnd]){
                int tempIndex = partOfTheList (towns[arrayIndex].paths[i].pathEnd, observationList);
                // not matching, insert
                if (tempIndex == -1){
                    valueHolder.setValue(towns[arrayIndex].paths[i].pathEnd, observationList[obs_ListIndex].totalCost + towns[arrayIndex].paths[i].pathLength);
                    observationList.push_back(valueHolder);
                }

                // matching, trial for replace
                else {
                    if (observationList[tempIndex].totalCost > observationList[obs_ListIndex].totalCost + towns[arrayIndex].paths[i].pathLength){
                        observationList[tempIndex].totalCost = observationList[obs_ListIndex].totalCost + towns[arrayIndex].paths[i].pathLength;
                    }
                }
            }
        }

        // eliminate
        observationList.erase(observationList.begin() + obs_ListIndex);
        for (int i = 0; i < observationList.size(); i++){
            if (observationList[i].totalCost >= minCost){
                observationList.erase(observationList.begin() + i);
                i--;
            }
        }

        // set new obs_ListIndex
        int smallest = 99999999;
        for (int i = 0; i < observationList.size(); i++){
            if (observationList[i].totalCost < smallest){
                smallest = observationList[i].totalCost;
                obs_ListIndex = i;
            }
        }
    }

    return minCost;
}
int partOfTheList (int townIndex, vector<ListItem>& observationList){
    for (int i = 0; i < observationList.size(); i++){
        if (observationList[i].indexOfTown == townIndex){
            return i;
        }
    }
    return -1;
}
void setPath (int ID1, int ID2, Town& townOne, Town& townTwo, int pathLength){
    Path valueHolder (ID2, pathLength);
    townOne.paths.push_back(valueHolder);

    valueHolder.setPath(ID1, pathLength);
    townTwo.paths.push_back(valueHolder);
}
