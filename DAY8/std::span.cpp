#include<iostream>
using namespace std;
#include<vector>
#include<span>

void print(std::span<int>s, int size){
	for(int v: s){
		cout<<v<<" ";
	}cout<<endl;
}

int main(){
	//std::vector<int> v= {1,2,3,4};
	//print(v);
	
	int *arr=new int[]{12,13,14,15};
	//print(arr,4);
	
	std::span<int> s(arr,4);
	for(int x:s){
		cout<<x<<" ";
	}cout<<endl;

	//int arr1[]={10,20,30};
	//print(arr1);
	return 0;
}
