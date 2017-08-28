/////////////////////***************  PRIORITY_QUEUE**************////////////////////

#include <iostream> // cout
#include <string> // string
#include <queue> // priority_queue
#include <iomanip> // setw

using namespace std;

struct MyTimeClass {
    int h;
    int m;
    int s;
};

struct EarlierFirstComparator {
    bool operator()(MyTimeClass& t1, MyTimeClass& t2) // Returns true if t1 is greater (later) than t2
    {
       if (t1.h > t2.h) return true;
       if (t1.h == t2.h && t1.m > t2.m) return true;
       if (t1.h == t2.h && t1.m == t2.m && t1.s > t2.s) return true;
       return false;
    }
};

struct Food {
    string name;
    int weight;

    Food(string _name, int _weight) : name(_name), weight(_weight) {}
};

struct HeavyFoodFirstComparator {
    bool operator()(Food& f1, Food& f2) // Returns true if f2 is heavier
       return f1.weight < f2.weight;
    }
};

int main()
{
    {
        cout << "====Sort string by default comparator====" << endl;
        // Creates a priority queue pq to store strings, and initializes the queue to be empty
        priority_queue<string> str_pq;

        str_pq.push("the quick");
        str_pq.push("fox");
        str_pq.push("jumped over");
        str_pq.push("the lazy dog");

        while (!str_pq.empty()) {
           cout << str_pq.top() << endl;  // Print highest priority string
           str_pq.pop();                  // Remmove highest priority string
        }
        cout << endl;
    }

    {
        cout << "====Sort times. earlier time first====" << endl;
        // Creates a priority queue pq  to store my own classes - MyTimeClass
        priority_queue<MyTimeClass, vector<MyTimeClass>, EarlierFirstComparator> my_pq;

        MyTimeClass t[4] = { {3, 2, 40}, {3, 2, 26}, {5, 16, 13}, {5, 14, 20}};
        for (int i = 0; i < 4; ++i) {
           my_pq.push(t[i]);
        }
        while (! my_pq.empty()) {
           MyTimeClass t2 = my_pq.top();
           cout << setw(2) << t2.h << ":" << setw(2) << t2.m << ":" << setw(2) << t2.s << endl;
           my_pq.pop();
        }
        cout << endl;
    }

    {
        cout << "====Sort Food objects by its weight descently====" << endl;
        priority_queue<Food, vector<Food>, HeavyFoodFirstComparator> my_pq;
        my_pq.push(Food("Banana", 12));
        my_pq.push(Food("Apple", 2));
        my_pq.push(Food("Orange", 200));
        my_pq.push(Food("Blackberry", 110));
        while (! my_pq.empty()) {
           Food f = my_pq.top();
           cout << f.name << " - " << f.weight << endl;
           my_pq.pop();
        }
        cout << endl;
    }

    return 0;
}
