#include <iostream>
#include <string>

using namespace std;

class QueueNode {
public:
    string name;
    QueueNode* next;

    QueueNode(string n) {
        name = n;
        next = nullptr;
    }
};

class QueueLinkedList {
public:
    QueueNode* front;
    QueueNode* rear;

    QueueLinkedList() {
        front = nullptr;
        rear = nullptr;
    }

    // Insert at Rear
    void enqueue(string name) {
        QueueNode* newNode = new QueueNode(name);
        if (rear == nullptr) {
            front = rear = newNode;
            return;
        }
        rear->next = newNode;
        rear = newNode;
    }

    // Delete from Front
    void dequeue() {
        if (front == nullptr) {
            cout << "This queue is empty." << endl;
            return;
        }
        QueueNode* temp = front;
        front = front->next;
        cout << "\n" << temp->name << " is dequeued." << endl;
        delete temp;

        if (front == nullptr) {
            rear = nullptr;
        }
    }

    void display() {
        if (front == nullptr) {
            cout << "The queue is empty." << endl;
            return;
        }
        QueueNode* current = front;
        while (current != nullptr) {
            cout << current->name << endl;
            current = current->next;
        }
    }
};

int main() {
    QueueLinkedList q;
    cout << "\n--- QUEUE (LINKED LIST) ---" << endl;
    q.enqueue("Aiman");
    q.enqueue("Ahmad");
    q.enqueue("Anajana");

    cout << "Display from front to rear:" << endl;
    q.display();

    q.dequeue();
    cout << "\nAfter dequeue:" << endl;
    q.display();
}
