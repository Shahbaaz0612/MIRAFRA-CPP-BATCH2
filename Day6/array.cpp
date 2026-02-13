#include<iostream>
#include<algorithm>
using namespace std;
#include<array>
int main()
{
	array<int, 5>arr = {1,2,3,4,5};

	cout<<"arr[2]: "<<arr[2]<<endl;
	cout<<"at(2): "<<arr.at(2)<<endl;

	cout<<"printing elements: "<<endl;
	for(auto i:arr){
		cout<<i<<" ";
	}
	cout<<endl;

	sort(arr.begin(), arr.end(),greater<int>());
	cout<<"reverse sorting:"<<endl;
	for(auto i:arr){
		cout<<i<<" ";
	}
	cout<<endl;

	array<int ,5>arr1 = {3,5,7,9,1};
	arr.swap(arr1);
	cout<<"after swapping arr with other arr1: "<<endl;
	for(auto i:arr){
		cout<<i<<" ";
	}
	cout<<endl;

	cout<<"printing using iterator arr: "<<endl;
	array<int,5> :: iterator it; //
	for(it= arr.begin(); it!= arr.end(); it++){
		cout<<*(it)<<" ";
	}
	cout<<endl;
	
	cout<<"size of array: "<<arr.size()<<endl;

	cout<<"fill all the elements with specified value: "<<endl;
	arr.fill(2);
	for(it= arr.begin(); it!= arr.end(); it++){
		cout<<*(it)<<" ";
	}
	cout<<endl;

}
