#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstdio>

using namespace std;

bool favTeamWon (int favTeam, int scores []) {
    int favScore = scores[favTeam];
    for (int i = 0; i < 6; i++) {
        if (i == favTeam) continue;
        if (favScore <= scores[i]) return false;
    }
    return true;
}

int timesWon (int favTeam ,int scores [], vector<pair<int,int> > gamesToPlay, string path) {
//cout << path << ":\t";
//for (int i = 0; i < 4; i++) cout << scores[i] << " ";
//cout << "\t";
//for (int i = 0; i < gamesToPlay.size(); i++) cout << gamesToPlay[i].first+1 << "," << gamesToPlay[i].second+1 << " ";
//cout << endl;

    int wins = 0;
    if (gamesToPlay.size() == 0) {
        if (favTeamWon(favTeam, scores)) return 1;
        else return 0;
    }
    else {

        pair <int,int> currGame = gamesToPlay.front();
        gamesToPlay.erase(gamesToPlay.begin());
        int tempScores [4];
        for (int i = 0; i < 4; i++) tempScores[i] = scores[i];

        tempScores[currGame.first] += 3;
        wins += timesWon(favTeam, tempScores, gamesToPlay, path+'W');
        for (int i = 0; i < 4; i++) tempScores[i] = scores[i];

        tempScores[currGame.second] += 3;
        wins += timesWon(favTeam, tempScores, gamesToPlay, path+'L');
        for (int i = 0; i < 4; i++) tempScores[i] = scores[i];

        tempScores[currGame.first] += 1;
        tempScores[currGame.second] += 1;
        wins += timesWon(favTeam, tempScores, gamesToPlay, path+'T');

    }

    return wins;
}

void test (const string& fileName) {
    ifstream myFile;
    myFile.open(fileName.c_str());

    int favTeam; int gamesPlayed;
    int scores [4] = {0, 0, 0, 0};
    myFile >> favTeam >> gamesPlayed; favTeam--;

    vector<pair<int,int> > gamesToPlay;
    gamesToPlay.push_back(pair<int,int>(0,1));
    gamesToPlay.push_back(pair<int,int>(0,2));
    gamesToPlay.push_back(pair<int,int>(0,3));
    gamesToPlay.push_back(pair<int,int>(1,2));
    gamesToPlay.push_back(pair<int,int>(1,3));
    gamesToPlay.push_back(pair<int,int>(2,3));

    for (int i = 0; i < gamesPlayed; i++) {
        int team1, team2, score1, score2;
        myFile >> team1 >> team2 >> score1 >> score2;
        team1--; team2--;
        if (score1 > score2) scores [team1] += 3;
        else if (score1 < score2) scores [team2] += 3;
        else {
            scores [team1] += 1;
            scores [team2] += 1;
        }

        for (int j = 0; j < gamesToPlay.size(); j++) {
            if (gamesToPlay[j].first == team1 && gamesToPlay[j].second == team2) {
                gamesToPlay.erase(gamesToPlay.begin()+j);
                break;
            }
        }
    }
    cout << timesWon (favTeam ,scores, gamesToPlay, "") << endl;
}

int main()
{
//    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013 SecondTime\\TestFiles\\S3\\test1.txt");
//    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013 SecondTime\\TestFiles\\S3\\test2.txt");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013 SecondTime\\TestFiles\\S3\\s3.1.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013 SecondTime\\TestFiles\\S3\\s3.2.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013 SecondTime\\TestFiles\\S3\\s3.3.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013 SecondTime\\TestFiles\\S3\\s3.4.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013 SecondTime\\TestFiles\\S3\\s3.5.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013 SecondTime\\TestFiles\\S3\\s3.6.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013 SecondTime\\TestFiles\\S3\\s3.7.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013 SecondTime\\TestFiles\\S3\\s3.8.in");

    return 0;
}
