#include <iostream>
using namespace std;

// Node class to represent elements in the linked list
class node {
public:
    int data;
    node* next;

    // Constructor to initialize a node with a given value
    node(int val) {
        data = val;
        next = NULL;
    }
};

// Function to insert a new node at the beginning of the linked list (head)
void insertAtHead(node* &head, int val) {
    // Create a new node with the given value
    node* n = new node(val);
    
    // If the list is empty, set the new node as the head and point it to itself
    if (head == NULL) {
        head = n;
        head->next = head;
        return;
    }

    // Update the next of the new node to point to the current head
    n->next = head;
    
    // Update the head to be the new node
    head = n;

    // Update the last node's next to point to the new head
    node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = head;
}

// Function to insert a new node at the end of the linked list (tail)
void insertAtTail(node* &head, int val) {
    // Create a new node with the given value
    node* n = new node(val);

    // If the list is empty, set the new node as the head and point it to itself
    if (head == NULL) {
        head = n;
        head->next = head;
        return;
    }

    // Traverse the list to find the last node
    node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }

    // Update the next of the last node to point to the new node
    temp->next = n;
    
    // Update the new node's next to point to the head, making it circular
    n->next = head;
}

// Function to search for a key in the linked list
bool search(node* head, int key) {
    // Start at the head of the list
    node* temp = head;
    
    // Traverse the circular list
    do {
        // If the current node's data matches the key, return true
        if (temp->data == key) {
            return true;
        }

        // Move to the next node
        temp = temp->next;
    } while (temp != head);

    // Key not found in the list, return false
    return false;
}

// Function to delete a node with a specific value from the linked list
void deletion(node* &head, int val) {
    // Start at the head of the list
    node* temp = head;

    // Traverse the circular list until the node before the one to be deleted
    do {
        if (temp->next->data == val) {
            // Save the node to be deleted
            node* todelete = temp->next;

            // Update the next pointer to skip the node to be deleted
            temp->next = temp->next->next;

            // Delete the node
            delete todelete;
            return;
        }

        // Move to the next node
        temp = temp->next;
    } while (temp != head);
}

// Function to delete the node at the head of the linked list
void deleteAtHead(node* &head) {
    // If the list is empty, return
    if (head == NULL)
        return;

    // Save the node to be deleted
    node* todelete = head;

    // Update the head to the next node
    head = head->next;

    // Update the last node's next to point to the new head
    node* temp = head;
    while (temp->next != todelete) {
        temp = temp->next;
    }
    temp->next = head;

    // Delete the node
    delete todelete;
}

// Function to display the elements of the linked list
void display(node* head) {
    // If the list is empty, return
    if (head == NULL)
        return;

    // Start at the head of the list
    node* temp = head;

    // Traverse the circular list and print each element
    do {
        cout << temp->data << "->";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

int main() {
    // Initialize an empty circular linked list
    node* head = NULL;

    // Insert elements at the end of the circular linked list
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);

    // Display the circular linked list
    display(head);

    // Insert an element at the beginning of the circular linked list
    insertAtHead(head, 4);

    // Display the circular linked list again
    display(head);

    // Search for a key in the circular linked list and print the result
    cout << search(head, 2) << "\n";
    
    // Delete the node with a specific value (e.g., delete node with value 3)
    deletion(head, 3);
    
    // Delete the node at the head of the circular linked list
    deleteAtHead(head);

    // Display the circular linked list after deletion
    display(head);

    // The main function returns 0 by default, indicating successful execution
    return 0;
}

