#include <iostream>
#include <fstream>
#include <set>
#include <vector>

using namespace std;

struct Student {
    set<int> bigger;
    set<int> smaller;
};

void findConnection (vector<Student>& students, int numberOfStudent, int tallerOne, int shorterOne){
    if (tallerOne == shorterOne){
        cout << "no" << endl;
    }
    else {
        bool found = false;
        set<int> oldList;
        oldList.insert(tallerOne);
        set<int> newList;
        while (true){
            for (set<int>::iterator it = oldList.begin(); it != oldList.end(); it++){
                for (set<int>::iterator it2 = students[*it].smaller.begin(); it2 != students[*it].smaller.end(); it2++){
                    newList.insert(*it2);
                }
            }
            if (newList.empty()) break;
            if (newList.find(shorterOne) != newList.end()) {
                cout << "yes" << endl;
                found = true;
                break;
            }
            oldList.clear();
            oldList = newList;
            newList.clear();
        }

        oldList.clear();
        oldList.insert(tallerOne);
        while (true){
            if (found) break;
            for (set<int>::iterator it = oldList.begin(); it != oldList.end(); it++){
                for (set<int>::iterator it2 = students[*it].bigger.begin(); it2 != students[*it].bigger.end(); it2++){
                    newList.insert(*it2);
                }
            }
            if (newList.empty()) break;
            if (newList.find(shorterOne) != newList.end()) {
                cout << "no" << endl;
                found = true;
                break;
            }
            oldList.clear();
            oldList = newList;
            newList.clear();
        }
        if (!found) cout << "unknown" << endl;
    }
}

void test (const string& fileName){
    ifstream myFile;
    myFile.open(fileName.c_str());

    int numberOfStudents;
    int comparison;

    myFile >> numberOfStudents >> comparison;

    if (numberOfStudents > 100000){
        numberOfStudents = 100000;
    }

    vector<Student> students;
    Student valueHolder;
    for (int i =0; i < numberOfStudents; i++){
        students.push_back(valueHolder);
    }
    for (int i = 0; i < comparison; i++){
        int a, b;
        myFile >> a >> b;
        a--; b--;
        if (a > size_t() || b > size_t()){
        }
        students[a].smaller.insert(b);
        students[b].bigger.insert(a);
    }
    int a, b;
    myFile >> a >> b;
    myFile.close();
    a--, b--;
    findConnection (students, numberOfStudents, a, b);

}

int power (int x){
    return x*x;
}


int main() {
    int x;
    int z;
    cin>> x;
    cin>> z;

    if (x == 9 && z == 1){
        cout << "that sounds like the game i played before tryouts";
    }

    return 0;
}

//    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013\\TestFiles\\S4\\s4.1-1.in");
//    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013\\TestFiles\\S4\\s4.1-2.in");
//    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013\\TestFiles\\S4\\s4.1-3.in");
//    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013\\TestFiles\\S4\\s4.1-4.in");
//    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013\\TestFiles\\S4\\s4.1-5.in");
//    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013\\TestFiles\\S4\\s4.2-1.in");
//    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013\\TestFiles\\S4\\s4.2-2.in");
//    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013\\TestFiles\\S4\\s4.2-3.in");
//    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013\\TestFiles\\S4\\s4.2-4.in");
//    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013\\TestFiles\\S4\\s4.2-5.in");
//    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013\\TestFiles\\S4\\s4.3-1.in");
//    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013\\TestFiles\\S4\\s4.3-2.in");
//    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013\\TestFiles\\S4\\s4.3-3.in");
//    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013\\TestFiles\\S4\\s4.3-4.in");
//    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013\\TestFiles\\S4\\s4.3-5.in");
//    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013\\TestFiles\\S4\\s4.4-1.in");
//    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013\\TestFiles\\S4\\s4.4-2.in");
//    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013\\TestFiles\\S4\\s4.4-3.in");
//    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013\\TestFiles\\S4\\s4.4-4.in");
//    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013\\TestFiles\\S4\\s4.4-5.in");
//    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013\\TestFiles\\S4\\s4.5-1.in");
//    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013\\TestFiles\\S4\\s4.5-2.in");
//    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013\\TestFiles\\S4\\s4.5-3.in");
//    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013\\TestFiles\\S4\\s4.5-4.in");
//    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013\\TestFiles\\S4\\s4.5-5.in");
//    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013\\TestFiles\\S4\\s4.6-1.in");
//    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013\\TestFiles\\S4\\s4.6-2.in");
//    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013\\TestFiles\\S4\\s4.6-3.in");
//    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013\\TestFiles\\S4\\s4.6-4.in");
//    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013\\TestFiles\\S4\\s4.6-5.in");
