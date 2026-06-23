#include <iostream>
#include <string>

using namespace std;

struct Node {
    string name;
    Node* next; 

    // Constructor 
    Node(string n) 
	 {
        name = n; 
        next = nullptr;
    }
};

struct LinkedList {
    Node* head; 

    LinkedList() 
	 {
        head = nullptr; 
    }

    // Insert at the end
    void insertEnd(string name) 
	{ 
        Node* newNode = new Node(name);

        if (head == nullptr) 
		  {
            head = newNode;
            return;
        }

        Node* current = head;
        while (current->next != nullptr) 
		  {
            current = current->next;
        }
        current->next = newNode;
    }

    // Insert after specific student
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
        current->next = newNode; 
    }

    // Delete student by name
    void deleteByName(string name) {
        if (head == nullptr) {
            return; 
        }
        if (head->name == name) {
            Node* temp = head;
            head = head->next;
            delete temp; 
            return;
        }

        Node* current = head;
        while (current->next != nullptr) {
            if (current->next->name == name) {
                Node* temp = current->next; 
                current->next = temp->next; 
                delete temp; 
                return;
            }
            current = current->next; 
        }
    }
    
    // Display all
    void display() {
        Node* current = head;
        if (current == nullptr) {
            cout << "The list is empty." << endl;
            return;
        }
        while (current != nullptr) {
            cout << current->name << endl;
            current = current->next;
        }
    }
};

int main() {
    LinkedList list;

    // Setting up the initial list
    list.insertEnd("Aimar");
    list.insertEnd("Anjana");
    list.insertEnd("Jessy");

    cout << "Initial list:" << endl;
    list.display();

    // Inserting Ali after Anjana
    list.insertAfter("Anjana", "Ali");

    // Appending Jane to the end
    list.insertEnd("Jane");

    // Deleting Jessy from the list
    list.deleteByName("Jessy");

    cout << "\nFinal list:" << endl;
    list.display();
    
    return 0;
}