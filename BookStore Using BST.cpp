#include <iostream>
#include <string>
using namespace std;

// Define a structure for a book
struct Book {
    string ISBN;
    string title;
    string author;
    string genre;
    int publishyear;

    // Overload the comparison operators for BST
    bool operator<(const Book& other) const {
        return ISBN < other.ISBN;
    }

    bool operator>(const Book& other) const {
        return ISBN > other.ISBN;  
    }
};

// Define a node structure for the Binary Search Tree
struct TreeNode {
    Book data;
    TreeNode* left;
    TreeNode* right;
    // Constructor
    TreeNode(const Book& item) : data(item), left(NULL), right(NULL) {}
};

// Binary Search Tree class
class BinarySearchTree {
private:
    TreeNode* root;

    // Private helper methods for tree traversal, insertion, deletion, etc.
    void searchByAuthorHelper(TreeNode* node, const string& author) const;
    void displayInOrder(TreeNode* node) const;

public:
    BinarySearchTree() : root(NULL) {}

    // Public methods for adding, searching, displaying books, etc.
    void insert(const Book& item);
    void searchByISBN(const string& ISBN) const;
    void searchByTitle(const string& title) const;
    void searchByAuthor(const string& author) const;
    void displayInOrder() const;
    void deleteBookrecord(const string& ISBN);
};

// Insert into BST
void BinarySearchTree::insert(const Book& item) {
    TreeNode* newNode = new TreeNode(item);
    
    if (root == NULL) {
        root = newNode;
        return;
    }
    
    TreeNode* current = root;
    TreeNode* parent = NULL;
    
    while (current != NULL) {
        parent = current;
        if (item < current->data) {
            current = current->left;
        } else if (item > current->data) {
            current = current->right;
        } else {
            cout << "Updating existing book with ISBN " << item.ISBN << "." << endl;
            current->data = item; // Update existing book with new information
            delete newNode; // Free memory allocated for newNode
            return;
        }
    }
    
    if (item < parent->data) {
        parent->left = newNode;
    } else {
        parent->right = newNode;
    }
}

// Search by ISBN
void BinarySearchTree::searchByISBN(const string& ISBN) const {
    TreeNode* current = root;
    
    while (current != NULL) {
        if (ISBN == current->data.ISBN) {
            cout << "Book found with ISBN " << ISBN << ":" << endl;
            cout << "Title: " << current->data.title << endl;
            cout << "Author: " << current->data.author << endl;
            cout << "Genre: " << current->data.genre << endl;
            cout << "Published Year: " << current->data.publishyear << endl;
            return;
        } else if (ISBN < current->data.ISBN) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    cout << "Book with ISBN " << ISBN << " not found." << endl;
}

// Search by Title
void BinarySearchTree::searchByTitle(const string& title) const {
    TreeNode* current = root;
    
    while (current != NULL) {
        if (title == current->data.title) {
            cout << "Book found with Title " << title << ":" << endl;
            cout << "ISBN: " << current->data.ISBN << endl;
            cout << "Author: " << current->data.author << endl;
            cout << "Genre: " << current->data.genre << endl;
            cout << "Published Year: " << current->data.publishyear << endl;
            return;
        } else if (title < current->data.title) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    cout << "Book with Title " << title << " not found." << endl;
}

// Search by Author
void BinarySearchTree::searchByAuthor(const string& author) const {
    cout << "Searching for books by author: " << author << endl;
    searchByAuthorHelper(root, author);
}

// Search by author helper
void BinarySearchTree::searchByAuthorHelper(TreeNode* node, const string& author) const {
    if (node == NULL) {
        return;
    }
    searchByAuthorHelper(node->left, author);
    if (node->data.author == author) {
        cout << "Book found with author " << author << ":" << endl;
        cout << "ISBN: " << node->data.ISBN << endl;
        cout << "Title: " << node->data.title << endl;
        cout << "Genre: " << node->data.genre << endl;
        cout << "Published Year: " << node->data.publishyear << endl;
        cout << endl;
    }
    searchByAuthorHelper(node->right, author);
}

// Helper function to delete a node
TreeNode* deleteNode(TreeNode* root, const string& ISBN) {
    if (root == NULL) {
        return NULL;
    }

    if (ISBN < root->data.ISBN) {
        root->left = deleteNode(root->left, ISBN);
    } else if (ISBN > root->data.ISBN) {
        root->right = deleteNode(root->right, ISBN);
    } else { // Node with ISBN to be deleted found
        if (root->left == NULL) {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        } else {
            TreeNode* successor = root->right;
            while (successor->left != NULL) {
                successor = successor->left;
            }
            root->data = successor->data;
            root->right = deleteNode(root->right, successor->data.ISBN);
        }
    }
    return root;
}

// Function to delete a node data
void BinarySearchTree::deleteBookrecord(const string& ISBN) {
    root = deleteNode(root, ISBN);
}

// Display all books in the record (in-order traversal)
void BinarySearchTree::displayInOrder(TreeNode* node) const {
    if (node == NULL) {
        return;
    }
    displayInOrder(node->left);
    cout << "ISBN: " << node->data.ISBN << endl;
    cout << "Title: " << node->data.title << endl;
    cout << "Author: " << node->data.author << endl;
    cout << "Genre: " << node->data.genre << endl;
    cout << "Published Year: " << node->data.publishyear << endl;
    cout << endl;
    displayInOrder(node->right);
}

void BinarySearchTree::displayInOrder() const {
    cout << "Books in the record:" << endl;
    displayInOrder(root);
}

// Main program
int main() {
    BinarySearchTree bst;
    int choice;
    string input;

    do {
        cout << "Select an operation:" << endl;
        cout << "1. Add a book" << endl;
        cout << "2. Search by ISBN" << endl;
        cout << "3. Search by Title" << endl;
        cout << "4. Search by author" << endl;
        cout << "5. Delete a book record" << endl;
        cout << "6. Display all books" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Clear input buffer

        switch (choice) {
            case 1: {
                Book newBook;
                cout << "Enter ISBN: ";
                getline(cin, newBook.ISBN);
                cout << "Enter title: ";
                getline(cin, newBook.title);
                cout << "Enter author: ";
                getline(cin, newBook.author);
                cout << "Enter genre: ";
                getline(cin, newBook.genre);
                cout << "Enter Published Year: ";
                cin >> newBook.publishyear;
                cin.ignore(); // Clear input buffer
                bst.insert(newBook);
                cout << "Book added successfully!" << endl;
                break;
            }
            case 2: {
                cout << "Enter ISBN to search: ";
                getline(cin, input);
                bst.searchByISBN(input);
                break;
            }
            case 3: {
                cout << "Enter Title to search: ";
                getline(cin, input);
                bst.searchByTitle(input);
                break;
            }
            case 4: {
                cout << "Enter Author to search: ";
                getline(cin, input);
                bst.searchByAuthor(input);
                break;
            }
            case 5: {
                cout << "Enter the Book ISBN to delete record: ";
                getline(cin, input);
                bst.deleteBookrecord(input);
                break;
            }
            case 6: {
                bst.displayInOrder();
                break;
            }
            case 7: {
                cout << "Exiting the program. Goodbye!" << endl;
                break;
            }
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 7);

    return 0;
}

