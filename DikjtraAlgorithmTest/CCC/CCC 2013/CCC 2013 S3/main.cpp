#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct Game{
    int teamOne;
    int teamTwo;

    void setValue (int _teamOne, int _teamTwo){
        teamOne = _teamOne;
        teamTwo = _teamTwo;
    }
    Game returnValue (int _teamOne, int _teamTwo){
        Game sub;
        sub.setValue(_teamOne, _teamTwo);
        return sub;
    }
};

int chanceOfWinning (int favouriteTeam, vector <Game> games, int teamScores []) {
    int timesWon = 0;
    if (games.empty()){
        bool success = true;
        for (int i = 0; i < 6; i++){
            if (i != favouriteTeam){
                if (teamScores[i] >= teamScores[favouriteTeam]){
                    success = false;
                    break;
                }
            }
        }
        if (success) timesWon++;
    }
    if (!games.empty()){
        int teamOne = games.front().teamOne;
        int teamTwo = games.front().teamTwo;
        games.erase(games.begin());
        teamScores[teamOne] += 3;
        timesWon += chanceOfWinning(favouriteTeam, games, teamScores);
        teamScores[teamOne] -= 3;
        teamScores[teamTwo] += 3;
        timesWon += chanceOfWinning(favouriteTeam, games, teamScores);
        teamScores[teamTwo] -= 3;
        teamScores[teamOne] += 1;
        teamScores[teamTwo] += 1;
        timesWon += chanceOfWinning(favouriteTeam, games, teamScores);
        teamScores[teamOne] -= 1;
        teamScores[teamTwo] -= 1;
    }
    return timesWon;
}

void test (const string& fileName){
    ifstream myFile;
    myFile.open(fileName.c_str());

    int teamScores [4] = {0, 0, 0, 0};
    vector <Game> games;
    Game valueHolder;
    {
        games.push_back(valueHolder.returnValue(0, 1));
        games.push_back(valueHolder.returnValue(0, 2));
        games.push_back(valueHolder.returnValue(0, 3));
        games.push_back(valueHolder.returnValue(1, 2));
        games.push_back(valueHolder.returnValue(1, 3));
        games.push_back(valueHolder.returnValue(2, 3));
    }

    int favouriteTeam;
    int alreadyPlayed;

    myFile >> favouriteTeam >> alreadyPlayed;
    favouriteTeam--;
    for (int i = 0; i < alreadyPlayed; i++){
        int teamOne, teamTwo, scoreOne, scoreTwo;
        myFile >> teamOne >> teamTwo >> scoreOne >> scoreTwo;
        teamOne--; teamTwo--;

        for (int j = 0; j < games.size(); j++)
            if (games[j].teamOne == teamOne && games[j].teamTwo == teamTwo)
                games.erase(games.begin() + j);

        if (scoreOne > scoreTwo) teamScores[teamOne] += 3;
        else if (scoreOne < scoreTwo) teamScores [teamTwo] += 3;

        else {
            teamScores[teamOne] += 1;
            teamScores[teamTwo] += 1;
        }
    }
    myFile.close();

    cout << chanceOfWinning (favouriteTeam, games, teamScores) << endl;
}

int main() {
//    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013\\TestFiles\\S3\\myOwnIn.txt");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013\\TestFiles\\S3\\s3.1.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013\\TestFiles\\S3\\s3.2.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013\\TestFiles\\S3\\s3.3.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013\\TestFiles\\S3\\s3.4.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013\\TestFiles\\S3\\s3.5.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013\\TestFiles\\S3\\s3.6.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013\\TestFiles\\S3\\s3.7.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013\\TestFiles\\S3\\s3.8.in");

    return 0;
}
