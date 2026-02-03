#include<iostream>
using namespace std;
int main()
{
	int var=10;
	const int *p=&var;//pointer to const
	int* const ptr=&var;//const pointer
	const int *const pt=&var;//both are constant
	
	*p=20;
	*ptr=40;
	*pt=50;
	cout<<*p<<endl;
	cout<<*ptr<<endl;
	cout<<*pt<<endl;		   
}
