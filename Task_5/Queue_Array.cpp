#include <iostream>
#include <string>

using namespace std;

class QueueArray {
public:
    string arr[100];
    int front;
    int rear;

    QueueArray() {
        front = -1;
        rear = -1;
    }

    void enqueue(string name) {
        if (rear == 99) {
            cout << "The queue is full." << endl;
            return;
        }
        if (front == -1) {
            front = 0;
        }
        rear++;
        arr[rear] = name;
    }

    void dequeue() {
        if (front == -1 || front > rear) {
            cout << "This queue is empty." << endl;
            return;
        }
        cout << "\n" << arr[front] << " is dequeued." << endl;
        front++;

        // Reset indicators if the queue becomes entirely exhausted
        if (front > rear) {
            front = rear = -1;
        }
    }

    void display() {
        if (front == -1 || front > rear) {
            cout << "This queue is empty." << endl;
            return;
        }
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << endl;
        }
    }
};

int main() {
    QueueArray q;
    cout << "\n--- QUEUE (ARRAY) ---" << endl;
    q.enqueue("Aiman");
    q.enqueue("Ahmad");
    q.enqueue("Anajana");

    cout << "Display from front to rear:" << endl;
    q.display();

    q.dequeue();
    cout << "\nAfter dequeue:" << endl;
    q.display();
}
