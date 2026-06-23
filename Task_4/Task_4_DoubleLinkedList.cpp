#include <iostream>
#include <string>
using namespace std;

struct Node {
    string name;
    Node* next; 
    Node* prev;

    Node(string n) {
        name = n;
        next = nullptr;
        prev = nullptr;
    }
};

struct DoublyLinkedList {
    Node* head;

    DoublyLinkedList() {
        head = nullptr;
    }

    // Insert at the very end of the list
    void insertEnd(string name) {
        Node* newNode = new Node(name);

        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current; // Connect new node back to old tail
    }

    // Insert a new student right after a target student name
    void insertAfter(string afterName, string newName) {
        Node* current = head;
        
        while (current != nullptr && current->name != afterName) {
            current = current->next;
        }

        if (current == nullptr) {
            cout << afterName << " not found." << endl;
            return;
        }

        Node* newNode = new Node(newName);
        newNode->next = current->next;
        newNode->prev = current;

        // If we aren't inserting at the absolute end, update the next node's backlink
        if (current->next != nullptr) {
            current->next->prev = newNode;
        }
        current->next = newNode;
    }

    // Delete a student node by name and heal broken links
    void deleteByName(string name) {
        if (head == nullptr) return;

        // Case 1: If the node to delete is the head
        if (head->name == name) {
            Node* temp = head;
            head = head->next;
            if (head != nullptr) {
                head->prev = nullptr;
            }
            delete temp;
            return;
        }

        // Case 2: Search the rest of the list
        Node* current = head;
        while (current->next != nullptr) {
            if (current->next->name == name) {
                Node* temp = current->next;
                current->next = temp->next;
                
                // If it isn't the last node, update the backlink of the next node
                if (temp->next != nullptr) {
                    temp->next->prev = current;
                }
                delete temp;
                return;
            }
            current = current->next;
        }
    }
    
    // Print forward from head to tail
    void display() {
        Node* current = head;
        if (current == nullptr) {
            cout << "The list is empty." << endl;
            return;
        }
        while (current != nullptr) {
            cout << current->name << " ";
            current = current->next;
        }
        cout << endl;
    }

    // Print backward from tail to head
    void displayReverse() {
        if (head == nullptr) {
            cout << "The list is empty." << endl;
            return;
        }

        Node* current = head;
        while (current->next != nullptr) {
            current = current->next; 
        }

        while (current != nullptr) {
            cout << current->name << " ";
            current = current->prev;
        } 
        cout << endl;
    }
};