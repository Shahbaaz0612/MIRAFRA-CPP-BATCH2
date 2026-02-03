#include<iostream>
using namespace std;

class point
{
	public:
		int x=10;
		int y=20;
		double length;
};

int main()
{
	int *ptr;
	int a=10;
	ptr=&a;
	int &ref=a;

	int b=100;
	ref=b;
	cout<<&ref<<endl;
	cout<<&a<<endl;
	cout<<ptr<<endl;
	cout<<&b<<endl;
	cout<<a<<endl;
}

