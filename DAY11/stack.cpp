#include<iostream>
using namespace std;
#define MAX 5
template <class T>
class stack{
	struct st;
	st arr[MAX];
	int top=-1;
	struct st{
		T pid;
		string process_name;
		bool running_status;	
		st() : pid(0), process_name(""),running_status(false){}
	};

	public:
	
	void push(T value, string name) : pid(value), process_name(name) {
		
		if(top == MAX){
			cout<<"stack is full.."<<endl;
		}
		if(top ==-1){
			top++;
		}
		running_status = true;
		arr[top++] = st;


	}

	void pop(){
		if(top ==-1){
			cout<<"stack is empty.."<<endl;
		}
		else{
			cout<<"data at top after popping element is: "<<arr[--top]<<endl;
		}
	}

	void peek(){
		cout<<"data at current location is: "<<arr[top]<<endl;
	}
};


int main{

	stack<int > sobj;
	sobj.push(10, "sensor");
}
