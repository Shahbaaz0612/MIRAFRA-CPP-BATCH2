#include<iostream>
using namespace std;
#include<queue>
#include<memory>
class LevelOrder{
	struct Node{
		unique_ptr<Node> left;
		unique_ptr<Node> right;
		int data;
		Node(int value) : data(value){}
	};

	unique_ptr<Node> root;

	void insertImpl(unique_ptr<Node>& root, int value){
		if(!root){
			root = make_unique<Node>(value);
		       return;
		}
 		if(value < root->data){
			insertImpl(root->left, value);
		}
		else if(value > root->data){
			insertImpl(root->right, value);
		}
	}
	
	void levelImpl(unique_ptr<Node>& root){
		queue<Node*> q;
		q.push(root.get());
		while(!q.empty()){
			Node* current = q.front();
			q.pop();
			cout<<current->data<<" ";
			if(current->left){
				q.push(current->left.get());
			}
			if(current->right){
				q.push(current->right.get());
			}
		}
	}

	
	public:
	void insert(int value){
		insertImpl(root,value);
	}

	void levelOrder(){
		levelImpl(root);
	}

};


int main(){
	LevelOrder obj;
	obj.insert(50);
	obj.insert(30);
	obj.insert(70);
	obj.insert(15);
	obj.insert(40);
	obj.insert(60);
	obj.insert(80);

	obj.levelOrder();

}
