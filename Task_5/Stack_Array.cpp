#include <iostream>
#include <string>

using namespace std;

class StackArray {
public:
    string arr[100];
    int top;

    StackArray() {
        top = -1; // -1 means empty stack
    }

    void push(string name) {
        if (top == 99) {
            cout << "The stack is full." << endl;
            return;
        }
        top++;
        arr[top] = name;
    }

    void pop() {
        if (top == -1) {
            cout << "The Stack is empty." << endl;
            return;
        }
        cout << "\n" << arr[top] << " is popped." << endl;
        top--;
    }

    void peek() {
        if (top == -1) {
            cout << "The Stack is empty." << endl;
            return;
        }
        cout << "Top element: " << arr[top] << endl;
    }

    void display() {
        if (top == -1) {
            cout << "The Stack is empty." << endl;
            return;
        }
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << endl;
        }
    }
};

int main() {
    StackArray s;
    cout << "\n--- STACK (ARRAY) ---" << endl;
    s.push("Aiman");
    s.push("Ahmad");
    s.push("Anajana");

    cout << "Display from top to bottom:" << endl;
    s.display();

    s.pop();
    cout << "\nAfter pop:" << endl;
    s.display();
}
