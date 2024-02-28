#include <iostream>
using namespace std;

// Node class to represent elements in the doubly linked list
class node {
public:
    int data;
    node* next;
    node* prev;

    // Constructor to initialize a node with a given value
    node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

// Function to insert a new node at the beginning of the doubly linked list (head)
void insertAtHead(node* &head, int val) {
    // Create a new node with the given value
    node* n = new node(val);

    // If the list is empty, set the new node as the head and return
    if (head !=NULL) {
        head->prev = n;
    }

    // Update the pointers of the new node and the current head
    n->next = head;
    
    head = n;
}

// Function to insert a new node at the end of the doubly linked list (tail)
void insertAtTail(node* &head, int val) {
    // Create a new node with the given value
    node* n = new node(val);

    // If the list is empty, set the new node as the head and return
    if (head == NULL) {
        insertAtHead(head,val);
        return;
    }

    // Traverse the list to find the last node
    node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Update the pointers of the new node and the last node
    temp->next = n;
    n->prev = temp;
}

// Function to insert a new node at a specific position in the doubly linked list
void insertAtPos(node* &head, int pos, int val) {
    // Create a new node with the given value
    node* n = new node(val);

    // If the list is empty or position is 1, insert at the head
    if (head == NULL || pos == 1) {
        insertAtHead(head, val);
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

    // Update the pointers of the new node and adjacent nodes
    n->next = temp->next;
    n->prev = temp;
    if (temp->next != NULL) {
        temp->next->prev = n;
    }
    temp->next = n;
}

// Function to reverse the doubly linked list
node* reverse(node* &head) {
    // Initialize pointers for traversal
    node* current = head;
    node* prev = NULL;

    // Traverse the list and reverse the pointers
    while (current != NULL) {
        // Save the next node before changing pointers
        node* next = current->next;
        
        // Reverse the pointers
        current->next = prev;
        current->prev = next;
        
        // Move to the next node
        prev = current;
        current = next;
    }

    // Update the head to the last node (prev)
    head = prev;
    return head;
}

void deleteAtHead(node* &head){
	node* todelete=head;
	head=head->next;
	head->prev=NULL;
	delete todelete;
}



void deletion(node* &head,int pos){
	if(pos==1){
		deleteAtHead(head);
		return;
	}
	node* temp=head;
	int count=1;
	
	while(temp!=NULL && count!=pos){
		temp=temp->next;
		count++;
	}
	
	temp->prev->next=temp->next;
	if(temp->next!=NULL){
		temp->next->prev=temp->prev;
	}
	
	delete temp;
}

// Function to display the elements of the doubly linked list
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

int main() {
    // Initialize an empty doubly linked list
    node* head = NULL;

    // Insert elements at the tail of the list
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);

    // Display the original doubly linked list
    cout << "Original doubly linked list:" << endl;
    display(head);
	
	insertAtHead(head, 5);
	insertAtHead(head, 6);
	display(head);
	deletion(head,1);
	display(head);
    //Reverse the doubly linked list
    head = reverse(head);

    //Display the reversed doubly linked list
    cout << "\nReversed doubly linked list:" << endl;
    display(head);

    return 0;
}

