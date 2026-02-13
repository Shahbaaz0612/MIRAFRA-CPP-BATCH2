#include<iostream>
#include<ranges>
using namespace std;
#include<vector>

int main(){

	vector<int> v = {1,2,3,4,5,6,7,8,9};
		     
		 //from v   -------------->  filter even elements  ----------> modify only even elements	
	auto result = v | std::views::filter([] (int x){ return x%2==0;}) | std::views::transform([](int x){ return x*x;});

	for(auto i: result){  // printing result..
		cout<<i<<" ";
	}cout<<endl;
}
