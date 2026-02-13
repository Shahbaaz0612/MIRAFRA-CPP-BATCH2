#include<iostream>
using namespace std;
#include<unordered_map>

int main(){

	unordered_map<int,int> sparse;
	sparse[3] = 5;
	sparse[6] = 3;

	cout<< "index 3 -> value: " << sparse[3] << endl;
	cout<< "index 6 -> value: " << sparse[6] << endl;	
	return 0;
}

