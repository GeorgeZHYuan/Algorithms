#include <iostream>
#include <vector>

using namespace std;

struct SingleRow {
    vector<char> theRow;
};

int main()
{
    for (int i = 0; i < 5; i++){
        SingleRow currentRow;
        char input;
        cin.get(input);
        if (input == ' ') currentRow.theRow.push_back(input);
        else currentRow.theRow.push_back(input);
        while (true){
            cin >> input;
            currentRow.theRow.push_back(input);
            if (input == '|') break;
        }
        vector <SingleRow> rows;
        rows.push_back(currentRow);

        cout << currentRow.theRow.size() << endl;
    }
}
