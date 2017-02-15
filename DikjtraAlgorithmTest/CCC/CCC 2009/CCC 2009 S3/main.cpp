#include <iostream>
#include <vector>
#include <set>
#include <stdlib.h>

using namespace std;
class ListItem {
    public:
        int arrayIndex;
        int distanceTraveled;


        ListItem (int _arrayIndex, int _distanceTraveled){
            arrayIndex = _arrayIndex;
            distanceTraveled = _distanceTraveled;
        }

        void setListItem (int _arrayIndex, int _distanceTraveled){
            arrayIndex = _arrayIndex;
            distanceTraveled = _distanceTraveled;
        }
};
class Profile {
    public:
        vector<int> contacts;
};

void connect (int personOne, int personTwo, Profile *profiles);
void disconnect (int personOne, int personTwo, Profile *profiles);

int friendsOfFreinds (int personOne, Profile profiles []);
int shortestDistance (int startLocationIndex, int endLocationIndex, Profile profiles []);

bool areConnected (int personOne, int personTwo, Profile profiles []);
int partofTheList(int webIndex, vector<ListItem>&);

int main() {
    vector <string> responses;

    char task;
    int personOne;
    int personTwo;

    Profile profiles [50];

    while (true){
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
        break;
    }

    while (task != 'q'){
        cin >> task;
        if (task == 'i'){
            cin >> personOne >> personTwo;
            personOne--;
            personTwo--;
            if (!areConnected(personOne, personTwo, profiles)){
                connect (personOne, personTwo, &(profiles [0]));
            }
        }
        else if (task == 'd'){
            cin >> personOne >> personTwo;
            personOne--;
            personTwo--;
            if (areConnected(personOne, personTwo, profiles)){
                disconnect (personOne, personTwo, &(profiles [0]));
            }
        }
        else if (task == 'n'){
            cin >> personOne;
            personOne--;
            int a = profiles[personOne].contacts.size();
            char buffer [33];
            itoa(a, buffer, 10);
            responses.push_back(buffer);

        }
        else if (task == 'f'){
            cin >> personOne;
            personOne--;
            int a = friendsOfFreinds (personOne, profiles);
            char buffer [33];
            itoa(a, buffer, 10);
            responses.push_back(buffer);
        }
        else if (task == 's'){
            cin >> personOne >> personTwo;
            personOne--;
            personTwo--;
            int temp = shortestDistance (personOne, personTwo, profiles);
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
    cout << endl;
    for (int i = 0; i < responses.size(); i++){
        cout << responses[i] << endl;
    }

    return 0;
}

int shortestDistance (int startLocationIndex, int endLocationIndex, Profile profiles []){
    if (startLocationIndex == endLocationIndex){
        return 0;
    }

    bool alreadyTraveled [50];
    for (int i = 0; i < 50; i++){
        alreadyTraveled [i] = false;
    }


    int obs_ListIndex = 0;
    vector<ListItem> observationList;

    ListItem tester (startLocationIndex, 0);
    observationList.push_back(tester);

    int webIndex = startLocationIndex;

    while (webIndex != endLocationIndex){
        alreadyTraveled [webIndex] = true;

        for (int i = 0; i < profiles[webIndex].contacts.size(); i++){
            if (!alreadyTraveled [profiles[webIndex].contacts[i]]){
                int tempIndex = partofTheList(profiles[webIndex].contacts[i], observationList);
                if (tempIndex < 0){
                    tester.setListItem (profiles[webIndex].contacts[i], (observationList[obs_ListIndex].distanceTraveled + 1));
                    observationList.push_back(tester);
                }
                else {
                    if (observationList[tempIndex].distanceTraveled > (observationList[obs_ListIndex].distanceTraveled + 1)){
                        observationList[tempIndex].distanceTraveled = (observationList[obs_ListIndex].distanceTraveled + 1);
                    }
                }
            }
        }
        observationList.erase(observationList.begin() + obs_ListIndex);

        if (observationList.empty()){
            return -1;
        }

        int currentShortest = observationList[0].distanceTraveled;
        for (int i = 0; i < observationList.size(); i++){
            if (observationList[i].distanceTraveled < currentShortest){
                currentShortest = observationList[i].distanceTraveled;
                obs_ListIndex = observationList[i].arrayIndex;
            }
        }

        webIndex = observationList[obs_ListIndex].arrayIndex;
    }

    return observationList[obs_ListIndex].distanceTraveled;
}

int partofTheList (int webIndex, vector<ListItem>& observationList){
    for (int i = 0; i < observationList.size(); i++){
        if (webIndex == observationList[i].arrayIndex){
            return i;
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
