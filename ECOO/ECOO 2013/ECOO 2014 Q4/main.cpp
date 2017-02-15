#include <iostream>
#include <vector>
#include <queue>

using namespace std;

float modifyPrice (vector<float> items, int ID, int place){
//cout << "item " << place << " which costed " << items[place];
    if (ID != 5){
        if (ID == 0) items[place] -= 50;
        else if (ID == 1) items[place] -= 10;
        else if (ID == 2) items[place] -= 5;
        else if (ID == 3) items[place] *= 0.8;
        else if (ID == 4) items[place] *= 0.9;
        if (items[place] < 0) items[place] = 0;
        items[place] *= 1.13;
    }
//cout << " now costs "  << items[place] << " using coupon " << ID << endl;
    return items[place];
}

float calculatePrice (vector<float> items, int first, int second, int place){
//cout << "items " << place << " " << place+1 << " costing " << items[place] << " " << items[place+1] << endl;
    float total = 0;
    int coups [2] = {first, second};
    for (int i = 0; i < 2; i++){
        if (coups[i] != 5){
            if (coups[i] == 0) items[place+i] -= 50;
            else if (coups[i] == 1) items[place+i] -= 10;
            else if (coups[i] == 2) items[place+i] -= 5;
            else if (coups[i] == 3) items[place+i] *= 0.8;
            else if (coups[i] == 4) items[place+i] *= 0.9;
            if (items[place+i] < 0) items[place+i] = 0;
            items[place+i] *= 1.13;
        }
        total += items[place+i];
    }
//cout << "Now costs " << items[place] << " " << items[place+1] << " using coupons " << first << " " << second << " with total " << total << endl;
    return total;
}

float bestPrice (int coupons [], vector<float>& items, int numberOfCoupons){
    if (coupons[6] > 0) coupons[6] = 1;
    int place;
    for (int i = 0; i < items.size(); i++){
        if (coupons[6] == 1 && i != items.size()-1){
        float mini = 99999999;
            for (int j = 0; j < 6; j++){
                if (coupons[j] < 1) continue;
                bool found = false;
                for (int k = 0; k < 6; k++){
                    if (coupons[k] < 1) continue;
                    if (k == j && k > 1 || k != j){
                        found = true;
                        float temp = calculatePrice(items, j, k, i);
//cout << "last best price was " << mini << endl;
                        if (temp < mini) {
                            mini = temp;
                            place = j;
                        }
//cout << "current best price is " << mini << endl;
                    }
                }
            }
//cout << "final price from non bogo is " << mini << endl;
            float BOGOtotal = 0;
            for (int j = 0; j < 2; j++){
                if (i+j != i+1) BOGOtotal += items[i+j]*1.13;
            }
//cout << "Bogo price is " << BOGOtotal << endl;
            if (mini < BOGOtotal){
//cout << "chosen regular coup" << endl;
                items[i] = modifyPrice(items, place, i);
                coupons[place]--;
            }
            else{
//cout << "chosen BOGO" << endl;
                items[i] *= 1.13;
                items.erase(items.begin()+i+1);
                coupons[6] --;
            }
        }
        else {
//cout << "No more BOGO coupon" << endl;
            float mini = 99999999;
            for (int j = 0; j < 6; j++){
//cout << "last best price was " << mini << endl;
                if (coupons[j] < 1) continue;
                float temp = modifyPrice(items, j, i);
                if (mini > temp) {
//cout << "new best price was " << temp << endl;
                    mini = temp;
                    place = j;
                }
//cout << "new best price was " << mini << endl;
            }
            items[i] = modifyPrice(items, place, i);
            coupons[place]--;
        }
    }
    float finalPrice = 0;
    for (int i = 0; i  < items.size(); i++) finalPrice += items[i];
    return finalPrice;
}

int main (){
    int numberOfItems, numberOfCoupons;
    cin >> numberOfItems;

    priority_queue <float> items;
    vector <float> theList;

    float temp;
    for (int i = 0; i < numberOfItems; i++){
        cin >> temp;
        items.push(temp);
    }

    while (!items.empty()){
        theList.push_back(items.top());
        items.pop();
    }

    cin >> numberOfCoupons;
    string temp2;
    int coupons [7] = {0, 0, 0, 0, 0, 0};
    for (int i = 0; i < numberOfCoupons; i++){
        cin >> temp2;
        if (temp2 == "$50") coupons[0] += 1;
        else if (temp2 == "$10") coupons[1] += 1;
        else if (temp2 == "$5") coupons[2] += 1;
        else if (temp2 == "20%") coupons[3] += 1;
        else if (temp2 == "10%") coupons[4] += 1;
        else if (temp2 == "TAX") coupons[5] += 1;
        else if (temp2 == "BOGO") coupons[6] += 1;
    }

    cout << "The best price is $" << bestPrice (coupons, theList, numberOfCoupons) << endl;
}
