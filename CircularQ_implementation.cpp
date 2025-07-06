#include <iostream>
#include <vector>
using namespace std;

class CircularQueue {
    vector<int> arr;
    int front, rear, size;

public:
    CircularQueue(int capacity) {
        size = capacity;
        arr.resize(size);
        front = rear = -1;
    }

    bool enqueue(int value) {
        // Check for full queue
        if ((front == 0 && rear == size - 1) || ((rear + 1) % size == front)) {
            cout << "Queue is Full" << endl;
            return false;
        }

        // First element
        if (front == -1) {
            front = rear = 0;
        }
        // Rear reached end but front is not at 0 -> wrap
        else if (rear == size - 1 && front != 0) {
            rear = 0;
        }
        else {
            rear = (rear + 1) % size;
        }

        arr[rear] = value;
        return true;
    }

    int dequeue() {
        if (front == -1) {
            cout << "Queue is Empty" << endl;
            return -1;
        }

        int ans = arr[front];
        arr[front] = -1; // Optional: clear slot

        // Only one element
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % size;
        }

        return ans;
    }

    void display() {
        if (front == -1) {
            cout << "Queue is Empty" << endl;
            return;
        }

        cout << "Queue: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % size;
        }
        cout << endl;
    }
};

int main() {
    CircularQueue cq(5); // capacity 5

    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(30);
    cq.enqueue(40);
    cq.enqueue(50);  // Should say Full if overflow

    cq.display();

    cout << "Dequeued: " << cq.dequeue() << endl;
    cout << "Dequeued: " << cq.dequeue() << endl;

    cq.display();

    cq.enqueue(60);
    cq.enqueue(70); // Wraps around

    cq.display();

    cout << "Dequeued: " << cq.dequeue() << endl;
    cq.display();

    return 0;
}
