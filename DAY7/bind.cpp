#include<iostream>
using namespace std;
#include<functional>

int sum(int x, int y, int z){
	return x+y+z;
}

auto lambda= [] (int a, int b, int c){
	return a+b+c;
};

int main()
{
	auto boundSum = bind(lambda, 10, placeholders::_1, placeholders::_2);

	cout<<"BoundSum: "<<boundSum(5, 7)<<endl;
}
