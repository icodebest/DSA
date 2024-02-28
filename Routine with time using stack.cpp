#include <iostream>
#include <string>

using namespace std;

// Define the maximum size of the stack and queue
const int MAX_SIZE = 100;

// Define the structure for a routine
struct Routine {
    string name;
    float executionTime;
    int priority;
};

// Define the stack class
class Stack {
private:
    Routine routines[MAX_SIZE];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(const Routine& routine) {
        if (top == MAX_SIZE - 1) {
            cout << "Stack Overflow! Cannot push more routines." << endl;
            return;
        }
        routines[++top] = routine;
    }

    Routine pop() {
        if (top == -1) {
            cout << "Stack is empty! Cannot pop." << endl;
            return {"", 0, 0}; // Return an empty routine
        }
        return routines[top--];
    }

    bool isEmpty() {
        return top == -1;
    }
};

// Define the queue class
class Queue {
private:
    Routine routines[MAX_SIZE];
    int front, rear;

public:
    Queue() {
        front = rear = -1;
    }

    void enqueue(const Routine& routine) {
        if ((front == 0 && rear == MAX_SIZE - 1) || (rear == (front - 1) % (MAX_SIZE - 1))) {
            cout << "Queue Overflow! Cannot enqueue more routines." << endl;
            return;
        } else if (front == -1) {
            front = rear = 0;
        } else if (rear == MAX_SIZE - 1 && front != 0) {
            rear = 0;
        } else {
            rear++;
        }
        routines[rear] = routine;
    }

    Routine dequeue() {
        if (front == -1) {
            cout << "Queue is empty! Cannot dequeue." << endl;
            return {"", 0, 0}; // Return an empty routine
        }
        Routine item = routines[front];
        if (front == rear) {
            front = rear = -1;
        } else if (front == MAX_SIZE - 1) {
            front = 0;
        } else {
            front++;
        }
        return item;
    }

    bool isEmpty() {
        return front == -1;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "The routines in the queue are displayed in order of priority:" << endl;
        if (rear >= front) {
            for (int i = front; i <= rear; i++) {
                cout << "Routine: " << routines[i].name << ", Execution Time: " << routines[i].executionTime
                     << ", Priority: " << routines[i].priority << endl;
            }
        } else {
            for (int i = front; i < MAX_SIZE; i++) {
                cout << "Routine: " << routines[i].name << ", Execution Time: " << routines[i].executionTime
                     << ", Priority: " << routines[i].priority << endl;
            }
            for (int i = 0; i <= rear; i++) {
                cout << "Routine: " << routines[i].name << ", Execution Time: " << routines[i].executionTime
                     << ", Priority: " << routines[i].priority << endl;
            }
        }
    }
};

int main() {
    // Create a stack and queue objects
    Stack stack;
    Queue queue;

    // Push routines onto the stack
    cout << "Pushing routines onto the stack:" << endl;
    stack.push({"Routine1", 2.5, 3});
    cout << "Routine1 (Priority 3, Execution Time 2.5)" << endl;
    stack.push({"Routine2", 1.8, 1});
    cout << "Routine2 (Priority 1, Execution Time 1.8)" << endl;
    stack.push({"Routine3", 3.2, 2});
    cout << "Routine3 (Priority 2, Execution Time 3.2)" << endl;
    stack.push({"Routine4", 2.0, 4});
    cout << "Routine4 (Priority 4, Execution Time 2.0)" << endl;
	cout<<endl;
    // Dequeue and enqueue routines from the stack to the queue
    cout << "Dequeueing and enqueuing routines from the stack to the queue:" << endl;
    for (int i = 0; i < 3; i++) {
        Routine routine = stack.pop();
        cout << "Dequeue " << routine.name << " from the stack and enqueue it in the queue." << endl;
        queue.enqueue(routine);
    }
	
	cout<<endl;
    // Display the routines in the queue
    cout << "Displaying the routines in the queue:" << endl;
    queue.display();

    return 0;
}

