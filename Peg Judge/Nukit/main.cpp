#include <iostream>

using namespace std;

int moves [5][4] = {{2, 1, 0, 2}, {1, 1, 1, 1}, {0, 0, 2, 1}, {0, 3, 0, 0}, {1, 0, 0, 1}};
bool situations [31][31][31][31];

bool winningSituaion (int a, int b, int c, int d) {
    if (a < 0 || b < 0 || c < 0 || d < 0) return false;
    else return !situations[a][b][c][d];
};

int main()
{
    for (int i = 0; i < 31; i++)
        for (int j = 0; j < 31; j++)
            for (int k = 0; k < 31; k++)
                for (int h = 0; h < 31; h++)
                    situations[i][j][k][h] = false;

    for (int i = 0; i < 31; i++)
        for (int j = 0; j < 31; j++)
            for (int k = 0; k < 31; k++)
                for (int h = 0; h < 31; h++)
                    for (int g = 0; g < 5; g++)
                        if (winningSituaion(i - moves[g][0], j - moves[g][1], k - moves[g][2], h - moves[g][3]))
                            situations[i][j][k][h] = true;
    int testCases, a, b, c, d;
    cin >> testCases;

    for (int trials = 0; trials < testCases; trials++) {
        cin >> a >> b >> c >> d;
        if (situations[a][b][c][d]) cout << "Patrick" << endl;
        else cout << "Roland" << endl;
    }

    return 0;
}
