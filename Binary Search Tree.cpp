#include <iostream>
using namespace std;

//Node Structire for BST
struct Node{
	int data;
	Node* left;
	Node* right;
	
	Node(int value){
		data=value;
		left=NULL;
		right=NULL;
	}
};

//function to insert a node in BST
Node* insert(Node* root, int value){
	if(root==NULL){
		return new Node(value);
	}
	if(value <root->data){
		root->left=insert(root->left,value);
	}
	else{
		root->right=insert(root->right,value);
	}
	
	return root;
}

//function to search a node in BST
Node* search(Node* root,int value){
	if(root==NULL){
		return NULL;
	}
	
	if(root->data==value){
		return root ;
	}
	else if(value < root->data){
		return search(root->left, value);	
	}
	else{
		return search(root->right,value);
	}
	
}

//function to delete a node from BST

Node* deleteNode(Node* root, int value){
	if(root==NULL){
		return root;
	}
	
	if(value <root->data){
		root->left=deleteNode(root->left,value);
	}
	else if(value >root->data){
		root->right=deleteNode(root->right,value);
	}
	//we find the value we want to delete Now:
	else{ 
		//if we have only right child
		if(root->left==NULL){ 
			Node* temp=root->right;
			delete root;
			return temp;
		}
		//if(we have only left child
		else if(root->right==NULL){
			Node* temp=root->left;
			delete root;
			return temp;
		}
		//if we have two child and we want to delete the parent so we create a successor of that 
		// should be
		// Initialize a pointer 'successor' to the right child of the node to be deleted
			Node* successor = root->right;
			
			// Traverse down the leftmost path of the right subtree to find the successor node
			while (successor->left != NULL) {
			    successor = successor->left;
			}
			
			// Replace the data of the node to be deleted with the data of its successor
			root->data = successor->data;
			
			// Recursively delete the successor node from the right subtree
			root->right = deleteNode(root->right, successor->data);
	}
}

//fucnction to Inorder traversal BST
void inorder(Node*root){
	if(root==NULL){
		return ;
	}
	
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

//fucnction to preorder traversal BST
void preorder(Node*root){
	if(root==NULL){
		return ;
	}
	cout<<root->data<<" ";
	inorder(root->left);
	inorder(root->right);
}

//function post order traversal BST
void postorder(Node* root){
	if(root==NULL){
		return ;
	}
	
	inorder(root->left);
	inorder(root->right);
	cout<<root->data<<" ";
}


//function for maxdepth of BST
int maxdepth(Node* root){
	if(root==NULL){
		return 0;
	}
	
	int leftdepth=maxdepth(root->left);
	int rightdepth=maxdepth(root->right);
	
	return 1+std::max(leftdepth,rightdepth);
}


int main(){
	Node* root=NULL;
	
	//Insert values
	root=insert(root,30);
	root=insert(root,20);
	root=insert(root,45);
	root=insert(root,32);
	root=insert(root,98);
	root=insert(root,10);
	
	//displaying the BST in differnt order
	cout<<"Inorder traversal of tree is : " ;
	inorder(root);
	cout<<endl<<"Preorder traversal of tree is : ";
	preorder(root);
	cout<<endl<<"Postorder traversal of tree is : ";
	postorder(root);
	
	cout<<endl;
	
	
	//delete the node in BST
	int valuetodelete;
	cout<<"Enter the velue to delete from BST";
	cin>>valuetodelete;
	
	deleteNode(root,valuetodelete);
	cout<<endl<<"After deleting the BST is "<<endl;
	inorder(root);
	
	cout<<endl;
	//searching the node from BST
	int key;
	cout<<"Enter the value to search in BST: ";
	cin>>key;
	if(search(root,key)){
		cout<<"Value found in BST "<<endl;
	}
	else{
		cout<<"Value not found";
	}
	
	cout<<endl;
	cout<<"*************************************"<<endl;
	cout<<endl<<"Inorder traversal of tree is : " ;
	inorder(root);
	cout<<endl<<"Preorder traversal of tree is : ";
	preorder(root);
	cout<<endl<<"Postorder traversal of tree is : ";
	postorder(root);
	
	cout<<endl;
	
	cout<<"Maximum depth of the BST is : ";
	maxdepth(root);
	
}

