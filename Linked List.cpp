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
    
    // Update the next of the new node to point to the current head
    n->next = head;
    
    // Update the head to be the new node
    head = n;
}

// Function to insert a new node at the end of the linked list (tail)
void insertAtTail(node* &head, int val) {
    // Create a new node with the given value
    node* n = new node(val);

    // If the list is empty, set the new node as the head and return
    if (head == NULL) {
        head = n;
        return;
    }

    // Traverse the list to find the last node
    node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Update the next of the last node to point to the new node
    temp->next = n;
}

//function to reverse the linked list

node* reverse(node* &head){
	node* prevptr=NULL;
	node* currptr=head;
	node* nextptr;
	
	while(currptr!=NULL){
		nextptr=currptr->next;
		currptr->next=prevptr;
		
		prevptr=currptr;
		currptr=nextptr;
	}
	
	return prevptr;
}



//Recursively reverse the Linked list

node* reverseRecursive(node* &head){
	
	if(head==NULL || head->next==NULL){
		return head;
	}
	
	// Corrected line: Assign the result of the recursive call to newhead
	node* newhead = reverseRecursive(head->next);
	
	head->next->next = head;
	head->next = NULL;
	
	return newhead;
}


// Function to search for a key in the linked list
bool search(node* head, int key) {
    // Start at the head of the list
    node* temp = head;
    
    // Traverse the list
    while (temp != NULL) {
        // If the current node's data matches the key, return true
        if (temp->data == key) {
            return true;
        }

        // Move to the next node
        temp = temp->next;
    }

    // Key not found in the list, return false
    return false;
}

// Function to delete a node with a specific value from the linked list
void deletion(node* &head, int val) {
    // Start at the head of the list
    node* temp = head;

    // Traverse the list until the node before the one to be deleted
    while (temp->next->data != val) {
        temp = temp->next;
    }

    // Save the node to be deleted
    node* todelete = temp->next;

    // Update the next pointer to skip the node to be deleted
    temp->next = temp->next->next;

    // Delete the node
    delete todelete;
}

// Function to delete the node at the head of the linked list
void deleteAtHead(node* &head) {
    // Save the node to be deleted
    node* todelete = head;

    // Update the head to the next node
    head = head->next;

    // Delete the node
    delete todelete;
}

// Function to display the elements of the linked list
void display(node* head) {
    // Start at the head of the list
    node* temp = head;

    // Traverse the list and print each element
    while (temp != NULL) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout <<"NULL" <<endl;
}

void insertAtPos(node* &head, int pos, int val) {
    // Create a new node with the given value
    node* n = new node(val);

    // If the position is 1, insert at the head
    if (pos == 1) {
        n->next = head;
        head = n;
        return;
    }

    // Traverse the list to find the node at position - 1
    node* temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    // If position is out of range, return
    if (temp == NULL) {
        cout << "Invalid position\n";
        return;
    }

    // Update the next pointer of the new node to point to the next node
    n->next = temp->next;

    // Update the next pointer of the previous node to point to the new node
    temp->next = n;
}




int main() {
    // Initialize an empty linked list
    node* head = NULL;

    
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
	insertAtTail(head, 4);
	
    // Display the linked list
    display(head);
    //Displey Simple Reverse 
    node* newhead=reverseRecursive(head);
    display(newhead);
  
    // Insert an element at the beginning of the linked list
    insertAtHead(head, 4);

    // Display the linked list again
    display(head);

    // Search for a key in the linked list and print the result
    cout << search(head, 2) << "\n";
    
    // Delete the node with a specific value (e.g., delete node with value 3)
    deletion(head, 3);
    
    // Delete the node at the head of the linked list
    deleteAtHead(head);

    // Display the linked list after deletion
    display(head);
  //The main function returns 0 by default, indicating successful execution
    return 0;
}

