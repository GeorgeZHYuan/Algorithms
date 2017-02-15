#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

struct Box {
    int l;
    int w;
    int h;

};

void organize (Box& item) {
    priority_queue <int> organizer;
    organizer.push(item.l);
    organizer.push(item.w);
    organizer.push(item.h);

    item.l = organizer.top();
    organizer.pop();
    item.w = organizer.top();
    organizer.pop();
    item.h = organizer.top();
}

int result (Box& item, vector<Box>& boxSizes){
    int best = 9999999999;
    for (int i = 0; i < boxSizes.size(); i++){
        if (item.l <= boxSizes[i].l && item.w <= boxSizes[i].w && item.h <= boxSizes[i].h) best = min (best, boxSizes[i].l*boxSizes[i].w*boxSizes[i].h);
    }
    if (best == 9999999999) return -1;
    return best;
}

void test (const string& fileName) {
    ifstream myFile;
    myFile.open(fileName.c_str());

    int boxSizes;
    myFile >> boxSizes;

    vector<Box> boxes;
    Box valueHolder;
    for (int i = 0; i < boxSizes; i++){
        myFile >> valueHolder.l >> valueHolder.w >> valueHolder.h;
        boxes.push_back(valueHolder);
    }

    for (int i = 0; i < boxes.size(); i++){
        organize (boxes[i]);
    }

    int items;
    myFile >> items;
    for (int i = 0; i < items; i++) {
        myFile >> valueHolder.l >> valueHolder.w >> valueHolder.h;
        organize (valueHolder);
        int temp = result (valueHolder, boxes);
        if (temp == -1) cout << "Item does not fit" << endl;
        else cout << temp << endl;
    }
    cout << endl;
    myFile.close();
}

int main()
{
//    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2007 SecondTime\\TestFiles\\s2\\testFile.txt");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2007 SecondTime\\TestFiles\\s2\\s2.1.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2007 SecondTime\\TestFiles\\s2\\s2.2.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2007 SecondTime\\TestFiles\\s2\\s2.3.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2007 SecondTime\\TestFiles\\s2\\s2.4.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2007 SecondTime\\TestFiles\\s2\\s2.5.in");

    return 0;
}
