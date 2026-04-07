#include<iostream>
using namespace std;
#include<memory>
class CAR{

	struct carDetails{
		string carName;
		string manufacturer;
		double rating;
		unique_ptr<carDetails> left;
		unique_ptr<carDetails> right;

		carDetails(string& cName, string& mName, double rtng) : carName(cName),manufacturer(mName),rating(rtng){}
	};
	public:
	unique_ptr<carDetails> root;
	
	CAR():root(nullptr){}
	
	void insert(string cName, string mName, double rtng){
		insertImpl(root, cName, mName, rtng);
	}
	
	void traversal(){
		inorderImpl(root);
	}

	private:
	void inorderImpl(const unique_ptr<carDetails>& root)const {
		if(!root){
			return;
		}
		root->rating = 10;
		inorderImpl(root->left);
		cout<<root->rating<<" ";
		inorderImpl(root->right);
	}

	void insertImpl(unique_ptr<carDetails>&temp, string cName, string mName, double rtng ){
		if(!temp) {
			temp = make_unique<carDetails>(cName, mName, rtng);
			return;
		}
		if(rtng > temp->rating){
			insertImpl(temp->right, cName, mName, rtng);
		}
		else if(rtng < temp->rating){
			insertImpl(temp->left, cName, mName, rtng);
		}
	}
};


int main(){
	CAR c1;
	c1.insert("punch", "TATA", 4);
 	c1.insert("Fortuner", "TOYOTA", 4.7);
	c1.insert("4matic", "BENZ", 5);

	c1.traversal();



}

