#include <iostream>
using namespace std;

// Node definition
struct Node {
    int data;
    Node* next;
};

// Queue class using linked list
class Queue {
private:
    Node* front;
    Node* rear;

public:
    // Constructor
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    // Enqueue (insert at rear)
    void enqueue(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;

        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }

        cout << value << " enqueued." << endl;
    }

    // Dequeue (remove from front)
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow!" << endl;
            return;
        }

        Node* temp = front;
        cout << "Dequeued: " << temp->data << endl;
        front = front->next;

        if (front == nullptr) {
            rear = nullptr; // If queue becomes empty
        }

        delete temp;
    }

    // Peek front element
    void peek() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
        } else {
            cout << "Front element: " << front->data << endl;
        }
    }

    // Check if empty
    bool isEmpty() {
        return front == nullptr;
    }

    // Display elements
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }

        Node* temp = front;
        cout << "Queue elements: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Destructor
    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }
};

// Main function to test
int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.display();

    q.dequeue();
    q.display();

    q.peek();

    return 0;
}
