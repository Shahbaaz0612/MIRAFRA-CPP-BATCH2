#include<iostream>
using namespace std;
#include<functional>

void fun(auto value) {
	cout<<"Inside fun(): "<<value<<endl;
}

int main() {

	int var=10;
	auto genericLambda = [var](auto x, auto y) { 
		return x+y+var;
	};
	
	cout<<"generic lambda: "<<genericLambda(2,5)<<endl;
	cout<<"generic lambda: "<<genericLambda(2.9,7.5)<<endl;

	fun(genericLambda(25 ,10));
}
