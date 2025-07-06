#include <iostream>
#include <vector>
using namespace std;

class Deque {
    vector<int> dq;
    int size;
    int front, rear;

public:
    Deque(int capacity) {
        size = capacity;
        dq.resize(size, -1);
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return (front == 0 && rear == size - 1) || (front == rear + 1);
    }

    bool isEmpty() {
        return (front == -1);
    }

    void insertFront(int key) {
        if (isFull()) {
            cout << "Deque is Full\n";
            return;
        }

        if (front == -1) { // Empty
            front = rear = 0;
        }
        else if (front == 0) {
            front = size - 1;
        }
        else {
            front = front - 1;
        }

        dq[front] = key;
    }

    void insertRear(int key) {
        if (isFull()) {
            cout << "Deque is Full\n";
            return;
        }

        if (front == -1) { // Empty
            front = rear = 0;
        }
        else if (rear == size - 1) {
            rear = 0;
        }
        else {
            rear = rear + 1;
        }

        dq[rear] = key;
    }

    void deleteFront() {
        if (isEmpty()) {
            cout << "Deque is Empty\n";
            return;
        }

        cout << "Deleted from Front: " << dq[front] << endl;
        dq[front] = -1; // Optional

        if (front == rear) {
            front = rear = -1;
        }
        else if (front == size - 1) {
            front = 0;
        }
        else {
            front = front + 1;
        }
    }

    void deleteRear() {
        if (isEmpty()) {
            cout << "Deque is Empty\n";
            return;
        }

        cout << "Deleted from Rear: " << dq[rear] << endl;
        dq[rear] = -1; // Optional

        if (front == rear) {
            front = rear = -1;
        }
        else if (rear == 0) {
            rear = size - 1;
        }
        else {
            rear = rear - 1;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Deque is Empty\n";
            return;
        }

        cout << "Deque: ";
        int i = front;
        while (true) {
            cout << dq[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % size;
        }
        cout << endl;
    }
};

int main() {
    Deque dq(5);

    dq.insertRear(10);
    dq.insertRear(20);
    dq.insertFront(5);
    dq.insertFront(2);
    dq.insertRear(25); // Should fill it

    dq.display();

    dq.deleteFront();
    dq.deleteRear();

    dq.display();

    dq.insertFront(1);
    dq.insertRear(30);

    dq.display();

    return 0;
}
