#include <iostream>
#include <vector>
using namespace std;

class Queue {
    vector<int> v;

public:
    // Add element at the end
    void insert(int x) {
        v.push_back(x);
    }

    // Remove element from the front
    void deletion() {
        if (v.empty()) {
            cout << "Queue Underflow\n";
            return;
        }
        cout << "Removed: " << v.front() << endl;
        v.erase(v.begin());  // O(n) time
    }

    void display() {
        if (v.empty()) {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Queue: ";
        for (int i = 0; i < v.size(); i++) {
            cout << v[i] << " ";
        }
        cout << endl;
    }

    int front() {
        if (v.empty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        return v.front();
    }

    bool isEmpty() {
        return v.empty();
    }

    int size() {
        return v.size();
    }
};

int main() {
    Queue q;

    q.insert(10);
    q.insert(20);
    q.insert(30);

    q.display();

    q.deletion();
    q.display();

    cout << "Front element: " << q.front() << endl;
    cout << "Size: " << q.size() << endl;

    return 0;
}
