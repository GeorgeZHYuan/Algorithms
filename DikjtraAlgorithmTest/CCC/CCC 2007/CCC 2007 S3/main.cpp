#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <queue>
#include <set>

using namespace std;

struct ListItem {
    int arrayIndex;
    int distanceTraveled;

    ListItem (){}
    ListItem (int _arrayIndex, int _distanceTraveled){
        arrayIndex = _arrayIndex;
        distanceTraveled = _distanceTraveled;
    }

    void setListItem (int _arrayIndex, int _distanceTraveled){
        arrayIndex = _arrayIndex;
        distanceTraveled = _distanceTraveled;
    }
};

struct Node {
    vector<int> connections;
};

int findShortestConnection (int one, int two, Node person [], int numberOfStudents){
    queue<ListItem> scanList;
    set<int> outList;
    ListItem valueHolder (one, -1);
    scanList.push(valueHolder);
    outList.insert(one);
    while (!scanList.empty()){
        ListItem currentItem (scanList.front());
        scanList.pop();
        if (currentItem.arrayIndex == two){
            return currentItem.distanceTraveled;
        }
        for (int i = 0; i < person[currentItem.arrayIndex].connections.size(); i++){
            int setSize = outList.size();
            outList.insert(person[currentItem.arrayIndex].connections[i]);
            if (outList.size() == setSize+1){
                valueHolder.setListItem(person[currentItem.arrayIndex].connections[i], currentItem.distanceTraveled+1);
                scanList.push(valueHolder);
            }
        }
    }
    return -1;
}

void test (const string& fileName){
    ifstream myFile;
    myFile.open(fileName.c_str());

    int numberOfStudents;
    myFile >> numberOfStudents;

    Node person [numberOfStudents];
    map <int, int> studentID;
    int counter = 0;
    for (int i = 0; i < numberOfStudents; i++){
        int students[2];
        myFile >> students[0] >> students[1];
        for (int j = 0; j < 2; j++){
            if (studentID.find(students[j]) == studentID.end()){
                pair <int, int> valueHolder (students[j], counter);
                counter++;
                studentID.insert(valueHolder);
            }
        }
        person[studentID[students[0]]].connections.push_back(studentID[students[1]]);
    }
    vector <int> responses;
    while (true){
        int one, two;
        myFile >> one >> two;
        if (one == 0 && two == 0){break;}
        responses.push_back(findShortestConnection (studentID[one], studentID[two], person, numberOfStudents));
    }
    for (int i  = 0; i < responses.size(); i++){
        if (responses[i] == -1){
            cout << "No" << endl;
        }
        else {
            cout << "Yes " << responses[i] << endl;
        }
    }
    cout << endl;
    myFile.close();
}

int main() {
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2007\\TestFiles\\s3\\s3.1.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2007\\TestFiles\\s3\\s3.2.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2007\\TestFiles\\s3\\s3.3.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2007\\TestFiles\\s3\\s3.4.in");

    return 0;
}
