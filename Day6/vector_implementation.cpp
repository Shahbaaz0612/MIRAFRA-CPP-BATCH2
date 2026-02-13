#include<iostream>
using namespace std;
#include<cassert>
template<class T>

class vector{
	size_t sz;
	size_t cap;
	T* data;
public:
	vector():data(nullptr),sz(0),cap(0){ }

	void push_back(const T& value) {
		if(sz==cap){
			grow();
		}
		data[sz++]=value;
	}

	vector(const vector& other){ //copy const..
			sz=other.sz;
			cap=other.cap;
			data = (cap==0) ? nullptr : new T(cap);
			for(int i=0; i<sz; i++){
				data[i]=other.data[i];
			}
	}
	

	vector& operator = (const vector& other){ // copy assign...
		if(this != &other){
			sz=other.sz;
			cap=other.cap;
			delete[] data;
			data=(cap==0) ? nullptr : new T(cap);
			for(int i=0; i<sz; i++){
				data[i] = other.data[i];
			}
		}
		return *this;
	}

	
	vector(vector&& other){ //move constr....
		sz=other.sz;
		cap=other.cap;
		data=other.data;
		other.sz=0;
		other.cap=0;
		other.data=nullptr;
	}

	vector& operator = (vector&& other){ //move assign...
		if(this != &other){
			sz=other.sz;
			cap=other.cap;
			delete[] data;
			data=other.data;
			other.data=nullptr;
			other.sz=0;
			other.cap=0;
		}
		return *this;
	}

	void pop_back(){
		data[sz-1]=0;
		sz--;
	}

	T& operator[] (size_t	index){
		return data[index];
	}

	T& at(size_t index){
		assert(index<sz);
		if(index>sz){ throw out_of_range("index out of range"); }
		return data[index];
	}

	size_t size()const {
		return sz;
	}

	size_t capacity()const {
		return cap;
	}

	void grow(){
		size_t newcap = (cap==0) ? 1 : cap*2;
		T *newdata = new T[cap];
		for(int i=0; i<sz; i++){
			newdata[i]=data[i];
		}
		delete[] data;
		data=newdata;
		cap=newcap;
	}

	void reserve(int size){
		if(size<=cap){return; }
		T *newdata = new T[size];
		for(int i=0; i<sz; i++){
			newdata[i] = data[i];
		}
		delete[] data;
		data=newdata;
		cap=size;
	}
		

	T* begin(){
		return data;
	}

	T* end(){
		return (data+sz);
	}
	
	T* rbegin(){
		return data+sz-1;
	}

	T* rend(){
		return data-1;
	}

};

int main()
{
	vector<char>vec;
	vec.push_back('A');
	vec.push_back('B');
	vec.push_back('C');
	vec.push_back('D');
	vec.pop_back();

	for(auto i: vec){
		cout<<i<<" ";
	}cout<<endl;
	
	cout<<"at(2): "<<vec.at(2)<<endl;//vec[2];
	cout<<"printing vec elements"<<endl;
	for(auto it=vec.rbegin(); it!=vec.rend(); it--){
		cout<<*(it)<<" ";
	}
	cout<<endl;

	vec.reserve(50);
	cout<<"capacity after reserve(50): "<<vec.capacity()<<endl;
	
	cout<<"coping vec to vec1.."<<endl<<"printing vec1 elements: "<<endl;
	vector<char>vec1=vec;
	for(auto i: vec1){
		cout<<i<<" ";
	}cout<<endl;

	vector<char>v;//empty vector
	vector<char>v1=v;//copy empty vector
	cout<<"size of v1 after coping empty v "<<v.size()<<endl;
	cout<<"vector v1 created and initialised from vector vec uisng copy assign"<<endl;
	v1=vec;//copy assignment...
	for(auto i: v1){
		cout<<i<<" ";
	}cout<<endl;

	v=move(vec);//move assign..
	cout<<"moved vec to empty vector v "<<endl<<"printing v elements"<<endl;
	for(auto i: v){
		cout<<i<<" ";
	}cout<<endl;

	vector<char>v5=move(v);//move constr...
	cout<<"moved v to empty vector v5 "<<endl<<"printing v5 elements"<<endl;
	for(auto i: v5){
		cout<<i<<" ";
	}cout<<endl;
	

}
