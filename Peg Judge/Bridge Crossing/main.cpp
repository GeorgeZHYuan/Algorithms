// this question on s5 wong on the naming groups

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Person {
    int time;
    string name;
};

struct Group {
    int time;
    string formation;

    Group () {
        formation = "";
    }
};

int maximumOf(Person people [], int start, int ending){
    int largest = 0;
    for (int i = start; i <= ending; i++){
        if (people[i].time > largest){
            largest = people[i].time;
        }
    }
    return largest;
}

string groupIndex (int theTime, int startPoint, Group groups []){
    for (int i = startPoint; i >= 0; i--){
        if (theTime == groups[i].time){
            return groups[i].formation;
        }
    }
}

void findBestPossibility (int groupSize, Person people [], int queueSize){
    int bestTime = 0;
    Group groups [queueSize];
    for (int i = 0; i < queueSize; i++){
        if ((i+1) <= groupSize){
            bestTime = maximumOf(people, 0, i);
            groups[i].time = bestTime;
            for (int j = 0; j <= i; j++){
                groups[i].formation += (people[j].name + " ");
            }
//cout << "new formation: " << groups[i].formation << endl << endl;
        }
        else {
            string latestFormation = "5";
            int newBestTime = 99999999;
            for (int j = i; j >= i - groupSize+1; j--){
                int sub = maximumOf(people, j ,i) + groups[j-1].time;
                if (sub <= newBestTime){
                    latestFormation = "5";
                    newBestTime = sub;
                    for (int k = j; k <= i; k++){
                        latestFormation += people[k].name + " ";
                    }
//cout << "add on is: " << latestFormation << endl;
//cout << "base name is: " << groups[j-1].formation << endl;
                    groups[i].time = newBestTime;
                    groups[i].formation = groups[j-1].formation + latestFormation;
                }
                bestTime = newBestTime;
            }

//cout << endl << "new formation: " << groups[i].formation << endl;
        }
    }

    cout << "Total Time: " << bestTime << endl;
    for (int i = 0; i < groups[queueSize-1].formation.size(); i++){
        if (groups [queueSize-1].formation[i] != '5'){
            cout << groups[queueSize-1].formation[i];
        }
        else {
            cout << endl;
        }
    }
}

int main () {
    int groupSize;
    int queueSize;

    cin >> groupSize >> queueSize;
    Person people [queueSize];

    for (int i = 0; i < queueSize; i++){
        cin >> people[i].name >> people[i].time;
    }

    findBestPossibility (groupSize, people, queueSize);
    return 0;
}
