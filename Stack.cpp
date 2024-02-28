#include <iostream>

const int MAX_SIZE = 100;  // Maximum size of the stack

class Stack {
private:
    int elements[MAX_SIZE];  // Using an array to store elements
    int top;  // Index of the top element

public:
    // Constructor to initialize the stack
    Stack() {
        top = -1;  // Initialize top to -1 indicating an empty stack
    }

    // Function to push an element onto the stack
    void push(int value) {
        if (top < MAX_SIZE - 1) {
            elements[++top] = value;
            std::cout << "Pushed: " << value << std::endl;
        } else {
            std::cout << "Stack overflow. Cannot push." << std::endl;
        }
    }

    // Function to pop an element from the stack
    void pop() {
        if (!isEmpty()) {
            int poppedValue = elements[top--];
            std::cout << "Popped: " << poppedValue << std::endl;
        } else {
            std::cout << "Stack is empty. Cannot pop." << std::endl;
        }
    }

    // Function to check if the stack is empty
    bool isEmpty() {
        return top == -1;
    }
};

int main() {
    // Creating a stack
    Stack myStack;

    // Pushing elements onto the stack
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    // Popping elements from the stack
    myStack.pop();
    myStack.pop();
    myStack.pop();
    myStack.pop();  // Attempting to pop from an empty stack

    return 0;
}

