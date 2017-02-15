#include <iostream>
#include <fstream>

using namespace std;

void test (const string& fileName) {
    ifstream myFile;
    myFile.open (fileName.c_str());
    for (int testCases = 0; testCases < 5; testCases++){
        int m, n, p, q;
        myFile >> m >> n >> p >> q;
        for (int i = 0; i < q; i++){
            for (int j = 0; j < n+p*2+q*2;j++)cout << "#";
            cout << endl;
        }
        for (int i = 0; i < p; i++){
            for (int k = 0; k < q; k++) cout << "#";
            for (int k = 0; k < n+p*2; k++) cout << "+";
            for (int k = 0; k < q; k++) cout << "#";
            cout << endl;
        }
        for (int i = 0; i < m; i++){
            for (int k = 0; k < q; k++) cout << "#";
            for (int k = 0; k < p; k++) cout << "+";
            for (int k = 0; k < n; k++) cout << ".";
            for (int k = 0; k < p; k++) cout << "+";
            for (int k = 0; k < q; k++) cout << "#";
            cout << endl;
        }
        for (int i = 0; i < p; i++){
            for (int k = 0; k < q; k++) cout << "#";
            for (int k = 0; k < n+p*2; k++) cout << "+";
            for (int k = 0; k < q; k++) cout << "#";
            cout << endl;
        }
        for (int i = 0; i < q; i++){
            for (int j = 0; j < n+p*2+q*2;j++) cout << "#";
            cout << endl;
        }
        cout << endl;
    }

    myFile.close();
}

int main()
{
    test ("C:\\Users\\ayuan\\Documents\\Computer\\Project\\TestFiles\\DATA1.txt");
    return 0;
}
