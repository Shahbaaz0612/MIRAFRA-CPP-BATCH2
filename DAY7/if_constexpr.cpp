#include<iostream>
using namespace std;
template <typename T>

void process(T value){
	if constexpr (sizeof(T) == 4)
	{
		cout<<"32 bit type"<<endl;
	}else{
		cout<<"Non 32 bit type"<<endl;
	}
}

int main (){
	process(10);
	process(3.5);
	process('A');
}
