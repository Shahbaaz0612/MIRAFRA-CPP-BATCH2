#include<iostream>
using namespace std;
#include<optional>
#include<memory>
#include<stack>

class ECU{

	public:
	struct Node{
		int error_id;
		unique_ptr<Node> left;
		unique_ptr<Node> right;

		Node(int id) : error_id(id){}
	};
	
	unique_ptr<Node> root;
	
	void insert_error(int value){
		insertImpl(root, value);
	}
	
	void remove_error(int value){
		removeImpl(root, value);
	}

	void inorder(){
		inorderImpl(root);
	}
	
	private:

	void inorderImpl(unique_ptr<Node>& root){
		stack<Node*> st;
		Node* current = root.get();
		while(current != nullptr || !st.empty()){
			while(current != nullptr){
				st.push(current);
				current = current ->left.get();
			}
			current = st.top();
			st.pop();
			current = current->right.get();
		}
	}
	
	void removeImpl(unique_ptr<Node>& root, int value){

		if(!root){
			return;
		}

		if(!root->left){
			root = move(root->right);
		}
		else if(!root->right){
			root = move(root->left);
		}
		else{
			if(!root->right && !root->left){
				Node* minValue = root->right.get();
				while(minValue->left){
					minValue = minValue->left.get();
				}
				root->error_id = minValue -> error_id;
				removeImpl(root->right, minValue -> error_id);
			}
		}

	}

	void insertImpl(unique_ptr<Node>& root, int value){
		if(!root){
			root = make_unique<Node>(value);
			return;
		}
		else{
			if(value > root->error_id){
				insertImpl(root->right, value);
			}
			else if(value < root->error_id){
				insertImpl(root->left, value);
			}
		}
	}

};

int main(){

	ECU e1;
	e1.insert_error(120);
	e1.insert_error(147);
	e1.insert_error(200);
	e1.insert_error(90);
	e1.inorder();
	e1.remove_error(90);


}



