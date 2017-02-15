#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <set>
#include <iterator>
#include <queue>

using namespace std;

struct Profile {
    vector<int> contacts;
};

struct ListItem {
    int webIndex;
    int travelDistance;
    ListItem () {}
    ListItem (int a, int b){
        webIndex = a;
        travelDistance = b;
    }
    void setListItem (int a, int b){
        webIndex = a;
        travelDistance = b;
    }
};



void connect (int personOne, int personTwo, Profile *profiles);
void disconnect (int personOne, int personTwo, Profile *profiles);
int friendsOfFreinds (int personOne, Profile profiles []);
bool areConnected (int personOne, int personTwo, Profile profiles []);

int dijktrasAlgorithmOne (int personOne, int personTwo, Profile profiles []);
int breadthFirstOne (int personOne, int personTwo, Profile profiles []);

void test (const string& fileName) {
    ifstream myFile;
    myFile.open(fileName.c_str());

    vector <string> responses;

    char task = '!';
    int personOne;
    int personTwo;

    Profile profiles [50];{
        profiles[0].contacts.push_back(5);

        profiles[1].contacts.push_back(5);

        profiles[2].contacts.push_back(3);
        profiles[2].contacts.push_back(4);
        profiles[2].contacts.push_back(5);
        profiles[2].contacts.push_back(14);

        profiles[3].contacts.push_back(2);
        profiles[3].contacts.push_back(4);
        profiles[3].contacts.push_back(5);

        profiles[4].contacts.push_back(2);
        profiles[4].contacts.push_back(3);
        profiles[4].contacts.push_back(5);

        profiles[5].contacts.push_back(0);
        profiles[5].contacts.push_back(1);
        profiles[5].contacts.push_back(2);
        profiles[5].contacts.push_back(3);
        profiles[5].contacts.push_back(4);
        profiles[5].contacts.push_back(6);

        profiles[6].contacts.push_back(5);
        profiles[6].contacts.push_back(7);

        profiles[7].contacts.push_back(6);
        profiles[7].contacts.push_back(8);

        profiles[8].contacts.push_back(7);
        profiles[8].contacts.push_back(9);
        profiles[8].contacts.push_back(11);

        profiles[9].contacts.push_back(8);
        profiles[9].contacts.push_back(10);

        profiles[10].contacts.push_back(9);
        profiles[10].contacts.push_back(11);

        profiles[11].contacts.push_back(8);
        profiles[11].contacts.push_back(10);
        profiles[11].contacts.push_back(12);

        profiles[12].contacts.push_back(11);
        profiles[12].contacts.push_back(13);
        profiles[12].contacts.push_back(14);

        profiles[13].contacts.push_back(12);

        profiles[14].contacts.push_back(2);
        profiles[14].contacts.push_back(12);

        profiles[15].contacts.push_back(16);
        profiles[15].contacts.push_back(17);

        profiles[16].contacts.push_back(15);
        profiles[16].contacts.push_back(17);

        profiles[17].contacts.push_back(15);
        profiles[17].contacts.push_back(16);
    }

    while (task != 'q'){
        myFile >> task;

        if (task == 'i'){
            myFile >> personOne >> personTwo;
            personOne--;
            personTwo--;
            if (!areConnected(personOne, personTwo, profiles)){
                connect (personOne, personTwo, &(profiles [0]));
            }
        }
        else if (task == 'd'){
            myFile >> personOne >> personTwo;
            personOne--;
            personTwo--;
            if (areConnected(personOne, personTwo, profiles)){
                disconnect (personOne, personTwo, &(profiles [0]));
            }
        }
        else if (task == 'n'){
            myFile >> personOne;
            personOne--;
            int a = profiles[personOne].contacts.size();
            char buffer [33];
            itoa(a, buffer, 10);
            responses.push_back(buffer);

        }
        else if (task == 'f'){
            myFile >> personOne;
            personOne--;
            int a = friendsOfFreinds (personOne, profiles);
            char buffer [33];
            itoa(a, buffer, 10);
            responses.push_back(buffer);
        }
        else if (task == 's'){
            myFile >> personOne >> personTwo;
            personOne--;
            personTwo--;
            // int temp = dijktrasAlgorithmOne (personOne, personTwo, profiles);
            int temp = breadthFirstOne (personOne, personTwo, profiles);
            if (temp < 0){
                responses.push_back("Not Connected");
            }
            else {
                char buffer [33];
                itoa(temp, buffer, 10);
                responses.push_back(buffer);
            }
        }
    }

    myFile.close();

    for (int i = 0; i < responses.size(); i++){
        cout << responses[i] << endl;
    }
    cout << endl;
}

int main(){
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2009\\TestFiles\\s3\\s3.1.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2009\\TestFiles\\s3\\s3.2.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2009\\TestFiles\\s3\\s3.3.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2009\\TestFiles\\s3\\s3.4.in");

    return 0;
}

int dijktrasAlgorithmOne (int personOne, int personTwo, Profile profiles []){
    int stepCounter = 0;
    set<int> scanList;
    set<int> newList;
    set<int> outList;
    scanList.insert(personOne);
    while (scanList.size() > 0){
        newList.clear();
        for (set<int>::iterator it = scanList.begin(); it != scanList.end(); it++){
            if (*it == personTwo) return stepCounter;
        }
        for (set<int>::iterator it = scanList.begin(); it != scanList.end(); it++){
            outList.insert(*it);
            for (int i = 0; i < profiles[*it].contacts.size(); i++){
                bool canInsert = true;
                for (set<int>::iterator ita = outList.begin(); ita != outList.end(); ita++) {
                    if (*ita == profiles[*it].contacts[i]){
                        canInsert = false;
                        break;
                    }
                }
                if (canInsert) newList.insert(profiles[*it].contacts[i]);
            }
        }
        scanList.clear();
        scanList = newList;
        stepCounter ++;
    }
    return -1;
}

int breadthFirstOne (int personOne, int personTwo, Profile profiles []) {
    queue<ListItem> scanList;
    set<int> outList;
    ListItem valueHolder (personOne, 0);
    scanList.push(valueHolder);
    outList.insert(scanList.front().webIndex);
    while (!scanList.empty()){
        ListItem temp (scanList.front());
        scanList.pop();
        if (temp.webIndex == personTwo) return temp.travelDistance;
        for (int i = 0; i < profiles[temp.webIndex].contacts.size(); i++){
            int originalSize = outList.size();
            outList.insert(profiles[temp.webIndex].contacts[i]);
            if (outList.size() == originalSize + 1){
                valueHolder.setListItem (profiles[temp.webIndex].contacts[i], temp.travelDistance+1);
                scanList.push(valueHolder);
            }
        }
    }
    return -1;
}

void connect (int personOne, int personTwo, Profile *profiles){
    (profiles + personOne) -> contacts.push_back(personTwo);
    (profiles + personTwo) -> contacts.push_back(personOne);
}

void disconnect (int personOne, int personTwo, Profile *profiles){
    for (int i = 0; i < 50; i++){
        for (int j = 0; j < ((profiles + personOne) -> contacts.size()); j++){
            if ((profiles + personOne) -> contacts[j] == personTwo){
                (profiles + personOne) -> contacts.erase((profiles + personOne) -> contacts.begin() + j);
                break;
            }
        }
        for (int j = 0; j < ((profiles + personTwo) -> contacts.size()); j++){
            if ((profiles + personTwo) -> contacts[j] == personOne){
                (profiles + personTwo) -> contacts.erase((profiles + personTwo) -> contacts.begin() + j);
                break;
            }
        }
    }
}

int friendsOfFreinds (int personOne, Profile profiles []){
    set<int> numberOfriends;
    for (int i = 0; i < profiles[personOne].contacts.size(); i++){
        for (int j = 0; j < profiles[profiles[personOne].contacts[i]].contacts.size(); j++){
            if (!areConnected(profiles[profiles[personOne].contacts[i]].contacts[j], personOne, profiles)){
                numberOfriends.insert(profiles[profiles[personOne].contacts[i]].contacts[j]);
            }
        }
    }
    return numberOfriends.size();
}

bool areConnected (int personOne, int personTwo, Profile profiles []){
    if (personOne == personTwo){
        return true;
    }

    for (int i = 0; i < profiles[personOne].contacts.size(); i++){
        if (profiles[personOne].contacts[i] == personTwo){
            return true;
        }
    }
    return false;
}

