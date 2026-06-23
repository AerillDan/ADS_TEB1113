#include <iostream>
#include <string>
using namespace std;

struct Node {
    string name;
    Node* next; 

    // Constructor 
    Node(string n) {
        name = n;
        next = nullptr;
    }
};

struct CircularLinkedList {
    Node* head;

    CircularLinkedList() 
	 {
        head = nullptr;
    }

    // Insert at end
    void insertEnd(string name) {
        Node* newNode = new Node(name);

        if (head == nullptr) {
            head = newNode;
            newNode->next = head; // Points back to itself to make it circular
            return;
        }

        // Travel to find the current last node
        Node* current = head;
        while (current->next != head) {
            current = current->next;
        }

        // Insert the new node at the end and maintain the circle
        current->next = newNode;
        newNode->next = head;
    }

    // Insert after specific student
    void insertAfter(string afterName, string newName) {
        if (head == nullptr) return;

        Node* current = head;
        bool found = false;

        // Use a do-while loop to scan the entire circle safely
        do {
            if (current->name == afterName) {
                Node* newNode = new Node(newName);
                newNode->next = current->next; 
                current->next = newNode;       

                found = true;
                return;
            }
            current = current->next;
        } while (current != head);

        if (found == false) 
		  {
            cout << afterName << " not found." << endl;
        }
    }

    // Delete by name
    void deleteByName(string name) {
        if (head == nullptr) return;

        // Case 1: If the node to delete is the head
        if (head->name == name) {
            Node* temp = head;
            
            if (head->next == head) 
			   {
                head = nullptr;
            } 
			   else 
				{
                // Find the last node so we can update its next pointer
                Node* current = head;
                while (current->next != head) 
					 {
                    current = current->next;
                }
                head = head->next;    
                current->next = head;
            }
            delete temp;
            return;
        }

        // Case 2: Deleting mid-list or tail nodes
        Node* current = head;
        while (current->next != head) {
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

        do {
            cout << current->name << " ";
            current = current->next;
        } while (current != head); 
        cout << endl;
    }
};

int main() {
    CircularLinkedList list;

    list.insertEnd("Aimar");
    list.insertEnd("Anjana");
    list.insertEnd("Jessy");

    cout << "Initial circular list:" << endl;
    list.display();

    cout << "\nAfter inserting Ali after Anjana:" << endl;
    list.insertAfter("Anjana", "Ali");
    list.display();

    cout << "\nAfter inserting Jane at the end:" << endl;
    list.insertEnd("Jane");
    list.display();    

    cout << "\nAfter deleting Jessy:" << endl;
    list.deleteByName("Jessy");
    list.display();

    return 0;
}