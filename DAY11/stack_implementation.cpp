#include<iostream>
using namespace std;
#include<array>

template <class T, size_t SIZE>
class stack{
	int top_index;
	array<T, SIZE> arr;

	public:
	stack(): top_index(-1){}

	void push(T value){
		if(top_index == SIZE){
			cout<<"stack is full.."<<endl;
		}
		else{
			arr[++top_index] = value;
		}
	}

	void pop(){
		if(top_index == -1){
			cout<<"stack is empty.."<<endl;
		}
		else{
			--top_index;
		}
	}
	
	bool empty()const{
	      return (top_index == -1);
	}

	int size()const{
		return top_index+1;
	}

	T top()const{
		if(top_index == -1){
			cout<<"stack is empty.."<<endl;
		}
		return arr[top_index];
	}
};

int main(){
	stack<int, 5> sobj;
	sobj.push(10);
	sobj.push(20);
	sobj.push(30);
	sobj.pop();
	cout<<"Top value: "<<sobj.top()<<endl;
	cout << "size: "<< sobj.size() << endl;
	cout << sobj.empty() << endl;
}







