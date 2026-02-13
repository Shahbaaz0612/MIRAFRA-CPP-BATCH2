#include<iostream>
using namespace std;
#include<vector>
#include<ranges>
#include<map>

int main()              //Lazy_Evaluation :- do the operation when it is needed only. 
{
	vector<int> v = {1,2,3,4,5,6};

	auto even = v | std::views::filter( [] (int x){ // Here operation doesn't happen, 
			return x % 2==0;		// its like these lines are not in the code, 
			} );				// untill it is used..
	cout<<"even: "<<endl;
	for(auto i: even) {        // now here it starts evaluating the each element in the even object
		cout << i <<" ";   // if we dont write this for loop even object will not be evaluated, so it saves time.
	}cout<<endl;
	
	auto square = v | std::views::transform( [] (int x) {
			return x * x;
			} );
	cout<<"Transformed vector:  "<<endl;
	for(auto i: square) {
		cout<<i<<" ";
	}cout<<endl;

	cout<<"finding even from v: "<<endl;
	for(auto i: even) {
		cout<<i<<" ";
	}cout<<endl;

	auto reversed = v | std::views::reverse;
	cout<<"Reversed: "<<endl;
	for(auto i: reversed){
		cout<<i<<" ";
	}cout<<endl;

	map<int ,string>m = {
		{1,"one"},
		{2,"two"},
		{3,"three"}
	};

	auto k = m | std::views::keys;
	cout<<"Map keys: ";
	for(auto i: k){
		cout<<i<<" ";
	}cout<<endl;




}
