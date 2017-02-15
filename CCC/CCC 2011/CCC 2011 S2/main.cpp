#include <iostream>

using namespace std;

int main()
{
    int questionAmmount;
    int correctAnswers;

    while (true){
        correctAnswers = 0;
        cin >> questionAmmount;
        string responses [questionAmmount];
        string answers [questionAmmount];

        for (int i = 0; i < questionAmmount; i++){
            cin >> responses [i];
        }

        for (int i = 0; i < questionAmmount; i++){
            cin >> answers[i];
            if (answers[i] == responses[i]){
                correctAnswers ++;
            }
        }

        cout << correctAnswers << endl;
    }

    return 0;
}
