#include <iostream>

struct Node {
    int data;
    Node* left = nullptr;
    Node* right = nullptr;
    
    Node(int val) { data = val; }
};

Node* insert(Node* root, int val) {
    // If we hit an empty spot, create and return the new node
    if (root == nullptr) {
        return new Node(val);
    }
    
    // Otherwise, travel down the tree
    if (val < root->data) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    
    return root; // Return the node pointer
}

void printTree(Node* root) {
    if (root != nullptr) {
        printTree(root->left);
        std::cout << root->data << " ";
        printTree(root->right);
    }
}

int main() {
    Node* root = nullptr;

    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);

    std::cout << "BST Elements: ";
    printTree(root); 
    std::cout << std::endl;

    return 0;
}