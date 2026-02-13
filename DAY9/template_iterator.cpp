#include<iostream>
using namespace std;
#include<list>
#include<vector>
#include<array>

template<typename Iterator>
void Print_all(Iterator first, Iterator last){
	while(first != last) {
		cout<< *first << " ";
		++first;
	}cout<<endl;
}

int main(){

	vector<int> v = {1,2,3,4};
	list<int> l ={10,20,30};
	array<int, 3> arr = {100, 200, 300};
	
	cout<<"vector: ";
	Print_all(v.begin(), v.end());

	cout<<"list: ";
	Print_all(l.begin(), l.end());
	
	cout<<"Array: ";
	Print_all(arr.begin(), arr.end());
	
	return 0;
}

