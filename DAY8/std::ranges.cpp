#include<iostream>
using namespace std;
#include<vector>
#include<ranges>
#include<algorithm>

int main(){
	vector<int> v = {4,2,6,1,8};

	std::ranges::sort(v);

	for(int x:v){
		cout<<x<<" ";
	}cout<<endl;
	
	auto it = std::ranges::find(v,4);

	if(it != v.end()){
		cout<<"Find 4 at index: "<<std::distance(v.begin(), it)<<endl;
	}
}



