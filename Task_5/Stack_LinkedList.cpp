#include <iostream>
#include <string>

using namespace std;

class Node {
public:
    string name;
    Node* next;

    Node(string n) {
        name = n;
        next = nullptr;
    }
};

class StackLinkedList {
public:
    Node* top;

    StackLinkedList() {
        top = nullptr;
    }

    // Add element to top (Insert at Head)
    void push(string name) {
        Node* newNode = new Node(name);
        newNode->next = top;
        top = newNode;
    }

    // Remove element from top (Delete from Head)
    void pop() {
        if (top == nullptr) {
            cout << "The Stack is empty." << endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        cout << "\n" << temp->name << " is popped." << endl;
        delete temp;
    }

    // View top element
    void peek() {
        if (top == nullptr) {
            cout << "The Stack is empty." << endl;
            return;
        }
        cout << "Top element: " << top->name << endl;
    }

    // Display top to bottom
    void display() {
        if (top == nullptr) {
            cout << "The Stack is empty." << endl;
            return;
        }
        Node* current = top;
        while (current != nullptr) {
            cout << current->name << endl;
            current = current->next;
        }
    }
};

int main() {
    StackLinkedList s;
    cout << "--- STACK (LINKED LIST) ---" << endl;
    s.push("Aiman");
    s.push("Ahmad");
    s.push("Anajana");

    cout << "Display from top to bottom:" << endl;
    s.display();

    s.pop();
    cout << "\nAfter pop:" << endl;
    s.display();
}
