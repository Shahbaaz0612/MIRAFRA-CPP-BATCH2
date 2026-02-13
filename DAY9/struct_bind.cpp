#include<iostream>
using namespace std;

struct S{
	mutable int x1 : 2;
	volatile double y1;
};

S f(){
	return S{1,2.4};
}

int main(){
	const auto [x,y] = f();
	cout<< x <<" " << y <<endl;
	 x=-2;
	//y=-2; const modify its const qualified
	cout<< x <<" " << y <<endl;
	
	S s_var;
	 auto [x2,y2] = f();
	x2 = 2;
	y2 = 0.8;
	cout<< x2 << " " << y2 <<endl;


	return 0;
}

