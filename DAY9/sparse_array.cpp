#include<iostream>
using namespace std;
#include<pair>
#include<vector>

class sparseArray{
	vector<pair<int,int>> data;
	public:
	void set(int value, int index){
		if(value!=0){
			data.push_back({index,value});
		}
	}

	int get(int index)const{
		for(const auto & [i,v]:data){
			cout<<i<<"->"<<v<<endl;
		}
	}

	void print()const{	
		for(const auto & [i,v]:data){
			cout<<i<<"->"<<v<<endl;
		}
	}

	
		









};

int main(){



	return 0;
}

