#include<iostream>
using namespace std;
#include<memory>
#include<optional>
struct node{
	int data;
	unique_ptr<node> left;
	unique_ptr<node> right;

	node(int val): data(val){}
};

void inorder(unique_ptr<node>& root) {
	if(!root){
		return;
	}
//	cout<<"Node data: "<<root->data << " | address: " << root.get() << " | left: " << root->left.get() << " | right: " <<root->right.get()<<endl;
	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}

void preorder(unique_ptr<node>& root){
	if(!root){
		return;
	}
	cout << root->data << " ";
	preorder(root->left);
	preorder(root->right);
}	

void postorder(unique_ptr<node>& root){
	if(!root){
		return;
	}
	postorder(root->left);
	postorder(root->right);
	cout << root->data << " ";
}

void insert(unique_ptr<node>& root, int value){
	
	if(!root){
		root = make_unique<node>(value);
		return ;
	}
	if(value < root->data){
		 insert(root->left, value);
	}
	else if(value > root->data){
		 insert(root->right, value);
	}

}

void removeImpl(unique_ptr<node>& root, int value) {
	if(!root)
		return;

	if(value < root->data)
		removeImpl(root->left, value);
	else if(value > root->data)
		removeImpl(root->right, value);
	else{
		if(!root->left && !root->right){
			root.reset();
		}
		else if(!root->left){
			root = move(root->right);
		}
		else if(!root->right){ 
			root = move(root->left);
		}
		else{
			node* minNode = root->right.get();
			while(minNode->left){
				minNode = minNode->left.get();
			}
			root->data = minNode->data;
			removeImpl(root->right, minNode->data);
		}
			
	}
}

optional<int> findMax(const unique_ptr<node>& root) {
	if(!root)
		return nullopt;
	node* current = root.get();
	while(current->right){
		current = root->right.get();
	}
	return current->data;
}


void removing(unique_ptr<node>& root, int value){
	removeImpl(root,value);
}


int main(){

	auto root = make_unique<node> (50);
	insert(root, 30);
	insert(root, 70);
	insert(root, 20);
	insert(root, 40);
	insert(root, 15);
	insert(root, 25);
	insert(root, 35);	
	insert(root, 45);	
	insert(root, 33);	
	insert(root, 37);	
	insert(root, 43);	
	
	removing(root,30);
	cout<<findMax(root)<<endl;	

	inorder(root); cout<<endl;
//	preorder(root);cout<<endl;
//	postorder(root);cout<<endl;

}
