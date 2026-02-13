#include<iostream>
using namespace std;
#include<vector>
#include<span>

void print(std::span<int> s, const string& name) {

	cout<<name<<": ";
	for(auto x: s){
		cout<<x<<" ";
	}cout<<endl;
}

int main(){

	vector<int> v = {10,20,30,40,50};

	std::span<int> s(v);

	auto first_half = s.first(2);
	auto last_half = s.last(2);
	auto middle = s.subspan(1,3);

	print(s,"Original");	
	print(first_half, "First_Half");
	print(last_half, "Last_Half");
	print(middle, "Middle");

	cout<<v.at(2)<<endl;

}

