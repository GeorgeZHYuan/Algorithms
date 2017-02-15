#include <iostream>

using namespace std;

int main()
{
    int eyes;
    int antenas;

    cin >> antenas >> eyes;

    if (antenas >= 3 && eyes <= 4){
        cout << "TroyMartian" << endl;
    }

    if (antenas <= 6 && eyes >= 2){
        cout << "VladSaturnian" << endl;
    }

    if (antenas <= 2 && eyes <= 3){
        cout << "GraemeMercurian" << endl;
    }


    return 0;
}
