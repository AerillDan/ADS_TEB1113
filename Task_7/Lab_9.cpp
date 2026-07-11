#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <unordered_map>

using namespace std;

// 1. Define the Linked List Node structure for the adjacency list
struct Node {
    char vertex;
    int weight;
    Node* next;
    
    // Constructor for easy node creation
    Node(char v, int w) : vertex(v), weight(w), next(nullptr) {}
};

// Helper function to insert a new node at the front of the linked list
void addEdge(unordered_map<char, Node*>& adj, char src, char dest, int weight) {
    Node* newNode = new Node(dest, weight);
    newNode->next = adj[src]; // Point new node to the current head
    adj[src] = newNode;       // Update head to the new node
}

// 2. Dijkstra's Algorithm tailored for linked lists and character nodes
unordered_map<char, int> dijkstra(unordered_map<char, Node*>& adj, char src) {
    // Min-heap storing pairs of (distance, vertex_name)
    priority_queue<pair<int, char>, vector<pair<int, char>>, greater<pair<int, char>>> pq;

    // Use a map to store distances for character keys
    unordered_map<char, int> dist;

    // Initialize all known vertices to infinity
    for (const auto& pair : adj) {
        dist[pair.first] = INT_MAX;
    }

    // Distance from source to itself is 0
    dist[src] = 0;
    pq.emplace(0, src);

    // Process the queue
    while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();

        int d = top.first;
        char u = top.second;

        // If this distance is outdated, skip it
        if (d > dist[u])
            continue;

        // 3. Traverse the linked list for the current vertex
        Node* curr = adj[u];
        while (curr != nullptr) {
            char v = curr->vertex;
            int w = curr->weight;

            // If we found a shorter path to v through u, update it
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.emplace(dist[v], v);
            }
            // Move to the next node in the linked list
            curr = curr->next;
        }
    }

    return dist;
}

int main() {
    char src = 'A'; // Using 'A' instead of 0

    // Unordered map acting as our array of linked list heads
    unordered_map<char, Node*> adj;

    // Initialize map keys to nullptr (empty lists)
    char nodes[] = {'A', 'B', 'C', 'D', 'E'};
    for (char n : nodes) adj[n] = nullptr;

    // Recreating your original graph mapping: 0=A, 1=B, 2=C, 3=D, 4=E
    addEdge(adj, 'A', 'B', 4);
    addEdge(adj, 'A', 'C', 8);

    addEdge(adj, 'B', 'A', 4);
    addEdge(adj, 'B', 'E', 6);
    addEdge(adj, 'B', 'C', 3);

    addEdge(adj, 'C', 'A', 8);
    addEdge(adj, 'C', 'D', 2);
    addEdge(adj, 'C', 'B', 3);

    addEdge(adj, 'D', 'C', 2);
    addEdge(adj, 'D', 'E', 10);

    addEdge(adj, 'E', 'B', 6);
    addEdge(adj, 'E', 'D', 10);

    // Run Dijkstra
    unordered_map<char, int> result = dijkstra(adj, src);

    // Print the results alphabetically
    for (char n : nodes) {
        cout << "Distance from " << src << " to " << n << " is: " << result[n] << "\n";
    }

    // Memory Cleanup (Good practice since we used 'new' keyword)
    for (auto& pair : adj) {
        Node* curr = pair.second;
        while (curr != nullptr) {
            Node* temp = curr;
            curr = curr->next;
            delete temp;
        }
    }

    return 0;
}#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <unordered_map>

using namespace std;

// 1. Define the Linked List Node structure for the adjacency list
struct Node {
    char vertex;
    int weight;
    Node* next;
    
    // Constructor for easy node creation
    Node(char v, int w) : vertex(v), weight(w), next(nullptr) {}
};

// Helper function to insert a new node at the front of the linked list
void addEdge(unordered_map<char, Node*>& adj, char src, char dest, int weight) {
    Node* newNode = new Node(dest, weight);
    newNode->next = adj[src]; // Point new node to the current head
    adj[src] = newNode;       // Update head to the new node
}

// 2. Dijkstra's Algorithm tailored for linked lists and character nodes
unordered_map<char, int> dijkstra(unordered_map<char, Node*>& adj, char src) {
    // Min-heap storing pairs of (distance, vertex_name)
    priority_queue<pair<int, char>, vector<pair<int, char>>, greater<pair<int, char>>> pq;

    // Use a map to store distances for character keys
    unordered_map<char, int> dist;

    // Initialize all known vertices to infinity
    for (const auto& pair : adj) {
        dist[pair.first] = INT_MAX;
    }

    // Distance from source to itself is 0
    dist[src] = 0;
    pq.emplace(0, src);

    // Process the queue
    while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();

        int d = top.first;
        char u = top.second;

        // If this distance is outdated, skip it
        if (d > dist[u])
            continue;

        // 3. Traverse the linked list for the current vertex
        Node* curr = adj[u];
        while (curr != nullptr) {
            char v = curr->vertex;
            int w = curr->weight;

            // If we found a shorter path to v through u, update it
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.emplace(dist[v], v);
            }
            // Move to the next node in the linked list
            curr = curr->next;
        }
    }

    return dist;
}

int main() {
    char src = 'A'; // Using 'A' instead of 0

    // Unordered map acting as our array of linked list heads
    unordered_map<char, Node*> adj;

    // Initialize map keys to nullptr (empty lists)
    char nodes[] = {'A', 'B', 'C', 'D', 'E'};
    for (char n : nodes) adj[n] = nullptr;

    // Recreating your original graph mapping: 0=A, 1=B, 2=C, 3=D, 4=E
    addEdge(adj, 'A', 'B', 4);
    addEdge(adj, 'A', 'C', 8);

    addEdge(adj, 'B', 'A', 4);
    addEdge(adj, 'B', 'E', 6);
    addEdge(adj, 'B', 'C', 3);

    addEdge(adj, 'C', 'A', 8);
    addEdge(adj, 'C', 'D', 2);
    addEdge(adj, 'C', 'B', 3);

    addEdge(adj, 'D', 'C', 2);
    addEdge(adj, 'D', 'E', 10);

    addEdge(adj, 'E', 'B', 6);
    addEdge(adj, 'E', 'D', 10);

    // Run Dijkstra
    unordered_map<char, int> result = dijkstra(adj, src);

    // Print the results alphabetically
    for (char n : nodes) {
        cout << "Distance from " << src << " to " << n << " is: " << result[n] << "\n";
    }

    // Memory Cleanup (Good practice since we used 'new' keyword)
    for (auto& pair : adj) {
        Node* curr = pair.second;
        while (curr != nullptr) {
            Node* temp = curr;
            curr = curr->next;
            delete temp;
        }
    }

    return 0;
}
