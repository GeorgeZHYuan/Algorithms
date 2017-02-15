#include <iostream>
#include <stack>

using namespace std;

bool simulate (int numberOfCarts, int cartValues []);

int main()
{
    // obtaining cases to deal with
    int numberOfCases;
    cout << "How many cases?: ";
    cin >> numberOfCases;
    bool results [numberOfCases];

    // obtaining carts for cases and their values
    for (int cases = 0; cases < numberOfCases; cases++){
        cout << endl << "Case: " << cases+1 << endl;
        int numberOfCarts;
        cout << "How many carts?: ";
        cin >> numberOfCarts;
        int cartValues [numberOfCarts];
        cout << "Enter cart values" << endl;
        for (int i = 0; i < numberOfCarts; i++){
            cin >> cartValues [i];
        }

        // solving cases
        results[cases] = simulate (numberOfCarts, cartValues);
    }

    // displaying results
    cout << endl << "Here are the results: " << endl;
    for (int cases = 0; cases < numberOfCases; cases++){
        if (results[cases]){
            cout << "Y" << endl;
        }
        else {
            cout << "N" << endl;
        }
    }
}

bool simulate (int numberOfCarts, int cartValues []){
    stack<int> mountain;
    stack<int> side;
    stack<int> lake;

    // initializing stacks
    for (int i = 0; i < numberOfCarts; i++){
        mountain.push(cartValues[i]);
    }

    // selection
    while (true){
        if (!mountain.empty()){
            if (side.empty()){
                side.push(mountain.top());
                mountain.pop();
            }
            else {
                if (mountain.top() > side.top()){
                    if (lake.empty() || lake.top() < side.top()){
                        lake.push(side.top());
                        side.pop();
                    }
                    else {
                        return false;
                    }
                }
                else {
                    if (!lake.empty() && mountain.top() < lake.top()){
                        return false;
                    }
                    else {
                        side.push(mountain.top());
                        mountain.pop();
                    }
                }
            }
        }
        else {
            break;
        }
    }
    return true;
}
