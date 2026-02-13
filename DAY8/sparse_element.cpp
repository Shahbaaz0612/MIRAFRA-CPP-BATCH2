#include<iostream>
using namespace std;
#include<vector>
struct sparseElements{
	int index;
	int value;
};


int main(){
//	sparseElements sparse;
	vector<sparseElements> sparse[10];
	vector<int> v = {0,0,0,5,0,0,7,0,0,0};
	int count=0;
	for(int i=0; i<v.size(); i++){
		if(v[i] != 0){
		sparse[count].index = i;
		sparse[count].value = v[i];
		count++;
		}
	}
	
	for(auto i=0; i<sparse.size(); i++){
		cout<<"index: "<<sparse[i].index<<" - value: "<<sparse[i].value<endl;
	}
		
	/*for(const auto& [index,value]: sparse){
		cout<<"index: "<<index<<" - value: "<<value<<endl;
	}*/
}

