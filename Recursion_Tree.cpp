#include <iostream>
#include <iomanip>
using namespace std;

// Define the maximum number of nodes
#define MAX_NODES 100

// Structure to represent a node in the recursion tree
struct Node {
    int size;  // Problem size at this node
    int level; // Depth level of this node
};

// Queue implementation for managing nodes
class Queue {
private:
    Node nodes[MAX_NODES];
    int front, rear;

public:
    Queue() : front(-1), rear(-1) {}

    bool isEmpty() {
        return front == -1;
    }

    void enqueue(Node node) {
        if (rear == MAX_NODES - 1) {
            cout << "Queue is full!" << endl;
            return;
        }
        if (front == -1) {
            front = 0; // First element
        }
        nodes[++rear] = node;
    }

    Node dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return {0, 0}; // Return a default node
        }
        Node node = nodes[front++];
        if (front > rear) {
            front = rear = -1; // Reset queue when empty
        }
        return node;
    }
};

// Function to print the recursion tree
void printRecursionTree(int a, int b, int depth) {
    Queue queue;
    Node initial = {100, 0}; // Initialize root node with size 100 and depth 0
    queue.enqueue(initial);

    while (!queue.isEmpty()) {
        Node current = queue.dequeue();

        // Print the current node with indentation based on its depth
        cout << setw(current.level * 4) << "" 
             << "Size: " << current.size << ", Level: " << current.level << endl;

        // If the current level is less than the maximum depth, enqueue child nodes
        if (current.level < depth) {
            for (int i = 0; i < a; ++i) {
                Node child;
                child.size = current.size / b; // Update problem size
                child.level = current.level + 1; // Increment depth level
                queue.enqueue(child);
            }
        }
    }
}

int main() {
    int a, b, depth;

    // Prompt the user for input
    cout << "Enter the number of subproblems (a): ";
    cin >> a;
    cout << "Enter the division factor (b): ";
    cin >> b;
    cout << "Enter the maximum depth of the recursion tree: ";
    cin >> depth;

    // Validate user inputs
    if (a <= 0 || b <= 1 || depth < 0) {
        cout << "Invalid input. Please ensure a > 0, b > 1, and depth >= 0." << endl;
        return 1;
    }

    // Print the recursion tree
    printRecursionTree(a, b, depth);

    return 0;
}
