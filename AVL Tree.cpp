#include <iostream>

using namespace std;

// Node structure for BST and AVL tree
struct Node {
    int data;
    Node* left;
    Node* right;
    int height; // For AVL tree only

    Node(int value){
    data=value;
	left=NULL;
	right=NULL; 
	height=1;	
	}
};

class AVL {
private:
    Node* root;

    // Helper function for insertion
    Node* insertHelper(Node* root, int value) {
        if (root == NULL)
            return new Node(value);
        
        if (value < root->data)
            root->left = insertHelper(root->left, value);
        else if (value > root->data)
            root->right = insertHelper(root->right, value);

        // Update height
        root->height = 1 + max(getHeight(root->left), getHeight(root->right));

        // Perform balancing
        int balance = getBalance(root);

        // Left Left Case
        if (balance > 1 && value < root->left->data)
            return rightRotate(root);

        // Right Right Case
        if (balance < -1 && value > root->right->data)
            return leftRotate(root);

        // Left Right Case
        if (balance > 1 && value > root->left->data) {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }

        // Right Left Case
        if (balance < -1 && value < root->right->data) {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }

    // Helper function for removal
    Node* removeHelper(Node* root, int value) {
        if (root == NULL)
            return root;

        if (value < root->data)
            root->left = removeHelper(root->left, value);
        else if (value > root->data)
            root->right = removeHelper(root->right, value);
        else {
            if (root->left == NULL || root->right == NULL) {
                Node* temp = root->left ? root->left : root->right;

                if (temp == NULL) {
                    temp = root;
                    root = NULL;
                } else {
                    *root = *temp;
                }
                delete temp;
            } else {
                Node* temp = minValueNode(root->right);
                root->data = temp->data;
                root->right = removeHelper(root->right, temp->data);
            }
        }

        if (root == NULL)
            return root;

        // Update height
        root->height = 1 + max(getHeight(root->left), getHeight(root->right));

        // Perform balancing
        int balance = getBalance(root);

        // Left Left Case
        if (balance > 1 && getBalance(root->left) >= 0)
            return rightRotate(root);

        // Left Right Case
        if (balance > 1 && getBalance(root->left) < 0) {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }

        // Right Right Case
        if (balance < -1 && getBalance(root->right) <= 0)
            return leftRotate(root);

        // Right Left Case
        if (balance < -1 && getBalance(root->right) > 0) {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }

    // Helper function for traversal
    void preOrderTraversal(Node* root) {
        if (root == NULL)
            return;
        
        cout << root->data << " ";
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }

    void inOrderTraversal(Node* root) {
        if (root == NULL)
            return;
        
        inOrderTraversal(root->left);
        cout << root->data << " ";
        inOrderTraversal(root->right);
    }

    void postOrderTraversal(Node* root) {
        if (root == NULL)
            return;
        
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        cout << root->data << " ";
    }

    // Helper functions for AVL balancing
    int getHeight(Node* root) {
        if (root == NULL)
            return 0;
        return root->height;
    }

    int getBalance(Node* root) {
        if (root == NULL)
            return 0;
        return getHeight(root->left) - getHeight(root->right);
    }

    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;

        x->right = y;
        y->left = T2;

        // Update heights
        y->height = 1 + max(getHeight(y->left), getHeight(y->right));
        x->height = 1 + max(getHeight(x->left), getHeight(x->right));

        return x;
    }

    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        y->left = x;
        x->right = T2;

        // Update heights
        x->height = 1 + max(getHeight(x->left), getHeight(x->right));
        y->height = 1 + max(getHeight(y->left), getHeight(y->right));

        return y;
    }

    Node* minValueNode(Node* root) { 
        Node* current = root;
        while (current && current->left != NULL)
            current = current->left;
        return current;
    }

public:
    AVL() : root(NULL) {}

    // Insertion method
    void insert(int value) {
        root = insertHelper(root, value);
    }

    // Removal method
    void remove(int value) {
        root = removeHelper(root, value);
    }

    // Traversal methods
    void preOrder() {
        preOrderTraversal(root);
        cout << endl;
    }

    void inOrder() {
        inOrderTraversal(root);
        cout << endl;
    }

    void postOrder() {
        postOrderTraversal(root);
        cout << endl;
    }
};

int main() {
    // Create an AVL tree
    AVL avl;

    // Insert elements
    avl.insert(50);
    avl.insert(30);
    avl.insert(70);
    avl.insert(20);
    avl.insert(35);
    avl.insert(60);
    avl.insert(80);
    avl.insert(15);
    avl.insert(25);
    avl.insert(40);
    avl.insert(55);
    avl.insert(10);

    // Perform traversals
    cout << "Pre-order traversal: ";
    avl.preOrder();
    cout << "In-order traversal: ";
    avl.inOrder();
    cout << "Post-order traversal: ";
    avl.postOrder();

    // Remove node with value 50
    avl.remove(50);

    cout << "\nAfter removing 50:\n";
    // Perform traversals after removal
    cout << "Pre-order traversal: ";
    avl.preOrder();
    cout << "In-order traversal: ";
    avl.inOrder();
    cout << "Post-order traversal: ";
    avl.postOrder();

    return 0;
}

