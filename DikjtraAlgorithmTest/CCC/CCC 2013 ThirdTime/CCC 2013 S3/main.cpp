#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int chancesOfWinning (int favTeam, vector<pair<int, int> > gamesToPlay, int scores []) {
    int winningChances = 0;
    if (gamesToPlay.empty()){
//cout << "no more games left and current score is: " << endl;
//for (int i = 0; i < 4; i++) cout << scores[i] << " ";
//cout << endl;
        for (int i = 0; i < 4; i++){
            if (i == favTeam) continue;
            if (scores[i] >= scores[favTeam]) return 0;
        }
        return 1;
    }
    else {
        int a = gamesToPlay.front().first;
        int b = gamesToPlay.front().second;
        gamesToPlay.erase(gamesToPlay.begin());

        scores [a] += 3;
        winningChances += chancesOfWinning (favTeam, gamesToPlay, scores);
        scores [a] -= 3;

        scores [b] += 3;
        winningChances += chancesOfWinning (favTeam, gamesToPlay, scores);
        scores [b] -= 3;

        scores [a] += 1;
        scores [b] += 1;
        winningChances += chancesOfWinning (favTeam, gamesToPlay, scores);
        scores [a] -= 1;
        scores [b] -= 1;

        return winningChances;
    }
}

void test (const string& fileName){
    ifstream myFile;
    myFile.open(fileName.c_str());
    int favoriteTeam, gamesPlayed;
    int scores [4] = {0, 0 ,0 ,0};
    vector<pair<int, int> > gamesToPlay;
    {
        gamesToPlay.push_back(pair<int,int>(0,1));
        gamesToPlay.push_back(pair<int,int>(0,2));
        gamesToPlay.push_back(pair<int,int>(0,3));
        gamesToPlay.push_back(pair<int,int>(1,2));
        gamesToPlay.push_back(pair<int,int>(1,3));
        gamesToPlay.push_back(pair<int,int>(2,3));
    }

    myFile >> favoriteTeam >> gamesPlayed; favoriteTeam--;
    int  a, b, c, d;
    for (int i = 0; i < gamesPlayed; i++){
        myFile >> a >> b >> c >> d;
        a--; b--;
        for (int j = 0; j < gamesToPlay.size(); j++){
            if (gamesToPlay[j].first == a && gamesToPlay[j].second == b) {
                gamesToPlay.erase(gamesToPlay.begin()+j);
                break;
            }
        }
        if (c > d) scores [a] += 3;
        else if (c < d) scores [b] += 3;
        else {
            scores [a] += 1;
            scores [b] += 1;
        }
    }
    cout << chancesOfWinning(favoriteTeam, gamesToPlay, scores) << endl;
    myFile.close();
}

int main()
{
//    test("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013 ThirdTime\\TestFiles\\s3\\testFile.txt");
    test("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013 ThirdTime\\TestFiles\\s3\\s3.1.in");
    test("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013 ThirdTime\\TestFiles\\s3\\s3.2.in");
    test("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013 ThirdTime\\TestFiles\\s3\\s3.3.in");
    test("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013 ThirdTime\\TestFiles\\s3\\s3.4.in");
    test("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013 ThirdTime\\TestFiles\\s3\\s3.5.in");
    test("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013 ThirdTime\\TestFiles\\s3\\s3.6.in");
    test("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013 ThirdTime\\TestFiles\\s3\\s3.7.in");
    test("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2013 ThirdTime\\TestFiles\\s3\\s3.8.in");

    return 0;
}
