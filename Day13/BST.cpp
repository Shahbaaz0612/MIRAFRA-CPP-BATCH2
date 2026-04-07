#include<iostream>
using namespace std;

struct node{
	int data;
	struct node* left;
	struct node* right;

	node(int val): data(val){}
};

void inorder(node *root) {
	if(root == nullptr){
		return;
	}
	cout<<"Node data: "<<root->data << " | address: " << root << " | left: " << root->left << " | right: " <<root->right<<endl;
	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}

void preorder(node* root){
	if(root == nullptr){
		return;
	}
	cout << root->data << " ";
	preorder(root->left);
	preorder(root->right);
}	


void postorder(node* root){
	if(root==nullptr){
		return;
	}
	postorder(root->right);
	postorder(root->left);
	cout << root->data << " ";
}

node* insert(node* root, int value){
	
	if(root == nullptr){
		return new node(value);
	}
	if(value < root->data){
		root->left = insert(root->left, value);
	}
	else if(value > root->data){
		root->right = insert(root->right, value);
	}
	return root;

}

void delete_tree(node* root){
	if(root == nullptr)
		return;
	delete_tree(root->left);
	delete_tree(root->right);

	cout<<"deleting node: "<<root->data << "address: " << root << endl;
	delete root;
}

int main(){
	node* root = new node(10);

	root = insert(root, 10);
	root = insert(root, 5);
	root = insert(root, 15);
	root = insert(root, 3);
	root = insert(root, 13);
	root = insert(root, 7);
	root = insert(root, 17);
	
	
	inorder(root); cout<<endl;
	preorder(root);cout<<endl;
	postorder(root);cout<<endl;
}
