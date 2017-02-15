#include <iostream>

using namespace std;

int main()
{
    // get number of friends
    int numberOfFriends;
    cout << "Number of friends: ";
    cin >> numberOfFriends;

    // establish friend list
    int friendList [numberOfFriends];
    for (int i = 0; i < numberOfFriends; i++){
        friendList [i] = i+1;
    }

    // get number of trials
    int numberOfTrials;
    cout << "number of trials for elimination: ";
    cin >> numberOfTrials;
    int trialOutakes [numberOfTrials];

    // establish out-takes for trials
    cout << "enter trials: " << endl;
    for (int i = 0; i < numberOfTrials; i++){
        cin >> trialOutakes [i];
    }

    // putting friend list through the elimination trial
    for (int eliminationRounds = 0; eliminationRounds < numberOfTrials; eliminationRounds ++){

        // eliminating
        for (int i = trialOutakes[eliminationRounds] - 1; i < numberOfFriends; i += trialOutakes[eliminationRounds]){
            friendList [i] = -1;
        }

        // making substitute list
        int counter = -1;
        int substitute [numberOfFriends];
        for (int i = 0; i < (numberOfFriends); i++){
            if (friendList[i] != -1){
                counter++;
                substitute[counter] = friendList[i];
            }
        }

        // transferring substitute list into original
        for (int i = 0; i < numberOfFriends; i++){
            if (i <= counter){
                friendList[i] = substitute [i];
            }
            else {
                friendList [i] = -1;
            }
        }
    }

    // displaying message
    cout << endl;
    for (int i = 0; i < numberOfFriends; i++){
        if (friendList[i] != -1){
            cout << friendList[i] << endl;
        }
    }
}
