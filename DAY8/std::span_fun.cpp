#include<iostream>
using namespace std;
#include<vector>
#include<span>


void fun(std::span<int> s){
	
	for(int& x : s){
		x = x*2;
	}
}

int main(){
	int size = 5;
	int *ptr = new int[size]{10,20,30,40,50};

	fun(std::span<int>(ptr,size));

	cout<<"after span.."<<endl;

	for(int i=0; i<size; i++){
		cout<<ptr[i]<<" ";
	} cout<<endl;

	delete[] ptr;
}

