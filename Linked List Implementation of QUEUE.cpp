//_**Linked List Implementation of QUEUE
//*
//*
#include <iostream>
using namespace std;

// Node class to represent elements in the queue
class Node {
public:
    int data;
    Node* next;

    // Constructor to initialize a node with a given value
    Node(int val) : data(val), next(nullptr) {}
};

// Queue class
class Queue {
private:
    Node* front;  // Front of the queue
    Node* rear;   // Rear of the queue

public:
    // Constructor to initialize an empty queue
    Queue() : front(nullptr), rear(nullptr) {}

    // Function to check if the queue is empty
    bool isEmpty() {
        return front == nullptr;
    }

    // Function to enqueue (push) an element into the queue
    void enqueue(int val) {
        // Create a new node with the given value
        Node* newNode = new Node(val);

        // If the queue is empty, set both front and rear to the new node
        if (isEmpty()) {
            front = rear = newNode;
            return;
        }

        // Otherwise, update the next of the current rear to point to the new node
        rear->next = newNode;
        
        // Update the rear to be the new node
        rear = newNode;
    }

    // Function to dequeue (pop) an element from the queue
    void dequeue() {
        // If the queue is empty, return
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue.\n";
            return;
        }

        // Save the node to be dequeued
        Node* toDequeue = front;

        // Update the front to the next node
        front = front->next;

        // If the queue becomes empty after dequeuing, update rear to nullptr
        if (front == nullptr) {
            rear = nullptr;
        }

        // Delete the node
        delete toDequeue;
    }

    // Function to display the elements in the queue
    void display() {
        // Start at the front of the queue
        Node* temp = front;

        // Traverse the queue and print each element
        cout << "Queue: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    // Create a queue
    Queue myQueue;

    // Enqueue elements into the queue
    myQueue.enqueue(10);
    myQueue.enqueue(20);
    myQueue.enqueue(30);

    // Display the queue
    myQueue.display();

    // Dequeue an element
    myQueue.dequeue();

    // Display the modified queue
    myQueue.display();

    return 0;
}
