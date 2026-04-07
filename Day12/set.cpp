#include<iostream>
using namespace std;
#include<set>

struct comparator{
	bool operator () (int a, int b)const {
		if(a == b){
			cout<<"duplicate found not inserted!!"<<endl;
		}
		return a<b;
	}
};

int main(){
	set<int, comparator> s = {7,3,5,2,8};
	s.insert(4);
	s.insert(2);
	for(auto i: s){
		cout<<i<<" ";
	}cout<<endl;
	
	if(s.find(2) != s.end()){
		cout<<"found 2 in set.."<<endl;
	}

	s.erase(2);
	cout<<"after erasing element 2: "<<endl;
	for(auto i: s){
		cout<<i<<" ";
	}cout<<endl;
	s.insert(3);

	cout<<"count of an element 3: "<<s.count(3)<<endl;
}
