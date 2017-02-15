#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <set>
#include <queue>

using namespace std;

struct ListItem {
    int arrayID;
    int pathWeight;

    ListItem (int a, int p): arrayID(a), pathWeight(p) {};
    ListItem giveValue (int a, int p) {
        ListItem valueHolder (a, p);
        return valueHolder;
    }
};

void addBond (int a,  int b, vector< map<int, int> >& users){
    (users[a])[b] = 5;
    (users[b])[a] = 5;
}

void deleteBond (int a,  int b, vector< map<int, int> >& users){
    (users[a]).erase(b);
    (users[b]).erase(a);
}

int friendsOfFriends (int userId, vector< map<int, int> >& users){
    set<int> friends;
    for (map<int,int>::iterator it = (users[userId]).begin(); it != (users[userId]).end(); it++){
        for (map<int,int>::iterator it2 = (users[it->first]).begin(); it2 != (users[it->first]).end(); it2++){
            if ((users[userId]).count(it2->first) == 0) friends.insert(it2->first);
        }
    }
    return friends.size() - 1;
}

int breadthFirst (int a,  int b, vector< map<int, int> >& users) {
    map<int,int> scannedList;
    queue <ListItem> scanList;
    ListItem valueHolder (a, 0);
    scanList.push(valueHolder);
    scannedList[a] = 10;
    while (!scanList.empty()){
        if (scanList.front().arrayID == b) return scanList.front().pathWeight;
        for (map<int,int>::iterator it = users[scanList.front().arrayID].begin(); it != users[scanList.front().arrayID].end(); it++){
            if (scannedList.count(it->first) == 0) {
                scannedList[it->first] = 5;
                scanList.push(valueHolder.giveValue(it->first, scanList.front().pathWeight+1));
            }
        }
        scanList.pop();
    }
    return -1;
}

void test (const string& fileName){
    ifstream myFile;
    myFile.open(fileName.c_str());
    map<int,int> temp;
    vector< map<int,int> > users;
    for (int i = 0; i < 50; i++) users.push_back(temp);
    {   // Original Friend Setups
        addBond(0, 5, users);
        addBond(1, 5, users);
        addBond(2, 3, users);
        addBond(2, 4, users);
        addBond(2, 5, users);
        addBond(2, 14, users);
        addBond(3, 4, users);
        addBond(3, 5, users);
        addBond(4, 5, users);
        addBond(5, 6, users);
        addBond(6, 7, users);
        addBond(7, 8, users);
        addBond(8, 9, users);
        addBond(8, 11, users);
        addBond(9, 10, users);
        addBond(10, 11, users);
        addBond(11, 12, users);
        addBond(12, 13, users);
        addBond(12, 14, users);
        addBond(15, 16, users);
        addBond(15, 17, users);
        addBond(16, 17, users);
    }

    char action;
    int x, y;

    while (true){
        myFile >> action;
        if (action == 'q') break;
        else if (action == 'i') {
            myFile >> x >> y;
            x--; y--;
            addBond(x, y, users);
        }
        else if (action == 'd') {
            myFile >> x >> y;
            x--; y--;
            deleteBond(x, y, users);
        }
        else if (action == 'n') {
            myFile >> x;
            x--;
            cout << users[x].size() << endl;
        }
        else if (action == 'f') {
            myFile >> x;
            x--;
            cout << friendsOfFriends (x, users) << endl;

        }
        else if (action == 's') {
            myFile >> x >> y;
            x--; y--;
            int result = breadthFirst(x, y, users);
            if (result == -1) cout << "Not Connected" << endl;
            else cout << result << endl;
        }
    } cout << endl;
    myFile.close();
}

int main()
{
//    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2009 SecondTime\\TestFiles\\s3\\testFile.txt");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2009 SecondTime\\TestFiles\\s3\\s3.1.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2009 SecondTime\\TestFiles\\s3\\s3.2.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2009 SecondTime\\TestFiles\\s3\\s3.3.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2009 SecondTime\\TestFiles\\s3\\s3.4.in");

    return 0;
}
