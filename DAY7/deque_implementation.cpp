#include<iostream>
using namespace std;
template<class T>
class deque{
	T* data;
	int size;
	int cap;
	public:
	deque():data(nullptr),size(0),cap(0){}

		deque(const deque& other){
			size=other.size;
			cap=other.cap;
			data=new T(size);
			for(int i=0;i<size;i++){
				data[i]=other.data[i];
			}
		}

