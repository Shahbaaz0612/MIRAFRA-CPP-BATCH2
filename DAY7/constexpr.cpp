#include<iostream>
using namespace std;

//constexpr function (c++14 and later)
constexpr int factorial(int n) {
	int result=1;
	//cin>>result; //error
	for(int i=1; i<=n; i++){
		result*=i;
	}
	return result;
}

int main() {
	//compile-time evaluation
	constexpr int f = factorial(5);

	//Runtime evaluation
	constexpr int n=6;
	int f1 = factorial(n);

	cout<<"f: "<<f<<endl;
	cout<<"f1: "<<f1<<endl;
}


