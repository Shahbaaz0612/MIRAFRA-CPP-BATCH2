#include<iostream>
using namespace std;
#include<list>

int main(){
	list<int> l1 = {1,2,3};
	list<int> l2 = {10,20};
	auto it = l2.begin();

	l1.splice(l1.end(), l2);
	for(auto x: l1){
		cout<<x<<" ";
	} cout<<endl;
}

