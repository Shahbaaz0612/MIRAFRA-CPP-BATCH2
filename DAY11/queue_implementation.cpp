#include<iostream>
using namespace std;
#include<list>

template<class T, size_t SIZE>
class queue{
	list<T> arr;
	int frnt;
	int rear;

	public:
	queue() : frnt(-1), rear(-1){}

	void push(T value){
		if(rear == SIZE-1){
			cout<<"queue is full.."<<endl;
			return;
		}
		if(arr.empty()){
			frnt++;
		}
		arr.push_back(value);
		rear++;
	}

	void pop(){
		if(arr.empty()){
			cout<<"queue is empty.."<<endl;
			return;
		}
		if(rear == 0){
			frnt--;
		}
		arr.pop_front();
		rear--;
		
	}

	T& front() {
		if(arr.empty()){
			//cout<<"queue is empty.."<<endl;
			throw runtime_error("queue is empty..\n");
		}
		return arr.front();
	}

	T& back() {
		if(arr.empty()){
			//cout<<"queue is empty.."<<endl;
			throw runtime_error("queue is empty..\n");
		}
		return arr.back();
	}
	 
	bool empty()const {
		return arr.empty();
	}

	int size()const {
		return arr.size();
	}


};

int main(){
	queue<int, 5> qobj;

	qobj.push(10);
	qobj.push(20);
	qobj.push(30);
	cout<<"front: "<<qobj.front()<<endl;
	cout<<"back: "<<qobj.back()<<endl;
	cout<<"size: "<<qobj.size()<<endl;
	cout<<"empty: "<<qobj.empty()<<endl;
	qobj.push(30);
	qobj.push(30);
	qobj.push(30);
	qobj.pop();
	qobj.pop();
	qobj.pop();
	qobj.pop();
	qobj.pop();
	qobj.pop();
	qobj.push(30);
	cout<<"back: "<<qobj.back()<<endl;


}
