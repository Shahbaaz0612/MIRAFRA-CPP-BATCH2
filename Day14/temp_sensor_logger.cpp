#include<iostream>
using namespace std;
#include<memory>
#include<optional>
#include<queue>

class sensorLogger{

	struct Node{
		int sensorId;
		double temperature;
		unique_ptr<Node> left;
		unique_ptr<Node> right;
		Node(int id, double temp) : sensorId(id), temperature(temp){} 
	};
	
	unique_ptr<Node> root;
	
	void insertImpl(unique_ptr<Node>& root, int id, double temp){
		if(!root){
			root = make_unique<Node>(id,temp);
			return;
		}
		
		if(temp > root->temperature){
			insertImpl(root->right, id, temp);
		}
		else if(temp < root->temperature){
			insertImpl(root->left, id, temp);
		}
	}
	
	public:
	void insert(int id, double temp){
		insertImpl(root, id, temp);
	}

	optional<double> maxTemp()const {
		if(!root){
			return nullopt;
		}
		else {
			Node* temp = root.get();
			while(temp->right){
				temp = temp->right.get();
			}
			return temp->temperature;
		}
	}

	optional<double> minTemp()const {
		if(!root){
			return nullopt;
		}
		else{
			Node* temp = root.get();
			while(temp->left){
				temp = temp->left.get();
			}
			return temp->temperature;
		}
	}

	bool search_id(int id){
		if(!root){
			return false;
		}
		queue<Node*> q;
		q.push(root.get());
		while(!q.empty()){
			Node* current = q.front();
			q.pop();
			if(current->sensorId == id){
				return true;
			}
			if(current -> left){
				q.push(current->left.get());
			}
			if(current -> right){
				q.push(current -> right.get());
			}
		}
		return false;
	}

	void inorderImpl(unique_ptr<Node>& root)const{
		if(!root){
			return;
		}
		inorderImpl(root->left);
		cout<<"Id: " << root->sensorId << ",temperature: " << root->temperature << endl;
		inorderImpl(root->right);
	}

	void inorder(){
		inorderImpl(root);
	}

};


int main(){
	sensorLogger obj;
	obj.insert(10, 56.7);
	obj.insert(25, 65.0);
	obj.insert(56, 32.5);
	obj.inorder();
	auto max = obj.maxTemp();
	if(max)
		cout << "Max: " << *max << endl;
       auto min = obj.minTemp();
       if(min)
	       cout << "Min: " << *min << endl;
	
	if(obj.search_id(25)){
		cout<<"sensorId 25 - found"<<endl;
	}
	else{
		cout<<"sensorId 25 - notFound"<<endl;
	}
}


