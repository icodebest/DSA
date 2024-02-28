#include <iostream>

using namespace std; // Using the std namespace to simplify code

const int MAX_SIZE = 5; // Maximum size of the queue

class Queue {
private:
    int front, rear;
    int elements[MAX_SIZE];

public:
    // Constructor to initialize queue
    Queue() {
        front = -1;
        rear = -1;
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return (front == -1 && rear == -1);
    }

    // Function to check if the queue is full
    bool isFull() {
        return (rear + 1) % MAX_SIZE == front;
    }

    // Function to enqueue (add) an element to the queue
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue.\n";
            return;
        }

        if (isEmpty()) {
            // If the queue is empty, set front and rear to 0
            front = rear = 0;
        } else {
            // Move rear to the next position in a circular manner
            rear = (rear + 1) % MAX_SIZE;
        }

        // Add the new element to the rear
        elements[rear] = value;
    }

    // Function to dequeue (remove) an element from the queue
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue.\n";
            return;
        }

        if (front == rear) {
            // If there is only one element, set front and rear to -1
            front = rear = -1;
        } else {
            // Move front to the next position in a circular manner
            front = (front + 1) % MAX_SIZE;
        }
    }

    // Function to get the front element of the queue
    int getFront() {
        if (isEmpty()) {
            cout << "Queue is empty. No front element.\n";
            return -1; // Return a special value for an empty queue
        }

        return elements[front];
    }

    // Function to display the elements of the queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }

        cout << "Queue elements: ";
        int i = front;
        do {
            cout << elements[i] << " ";
            i = (i + 1) % MAX_SIZE;
        } while (i != (rear + 1) % MAX_SIZE);

        cout << endl;
    }
};

int main() {
    // Create a queue
    Queue myQueue;

    // Enqueue some elements
    myQueue.enqueue(5);
    myQueue.enqueue(10);
    myQueue.enqueue(15);

    // Display the front element
    cout << "Front element: " << myQueue.getFront() << endl;

    // Dequeue an element
    myQueue.dequeue();

    // Display the updated queue
    myQueue.display();

    // Enqueue more elements
    myQueue.enqueue(20);
    myQueue.enqueue(25);

    // Display the updated queue
    myQueue.display();

    // Enqueue one more element (will show a full queue message)
    myQueue.enqueue(30);

    return 0;
}

