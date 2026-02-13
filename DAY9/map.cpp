#include<iostream>
using namespace std;
#include<map>

int main(){
	
	map<int,string> m = { {1,"one"},{2,"two"} };
	
	for(const auto& [key,value] : m){
			cout << key << " -> " << value << endl;
	}
	
	for(const auto& element : m){
			cout << element.first << " -> " << element.second << endl;
	}
	return 0;
}

