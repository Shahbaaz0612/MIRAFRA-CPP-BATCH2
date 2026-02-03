#include<iostream>
using namespace std;

int& fun(int&);
int& fun(int& a)//(const int& a) --> if parameter accepted as const cant modify it 
{
	a=a*2;
	static int l=100;
	int& r=l;
		return r;
}

int main()
{
	int num=5;
	int& l_ref=fun(num);
	cout<<num<<endl;
	cout<<l_ref<<endl;
};
