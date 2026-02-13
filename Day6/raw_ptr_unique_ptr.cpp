#include<iostream>
#include<memory>
using namespace std;
int main(){
	//int x=10;
	int *p = new int(10);
	unique_ptr<int>ptr1(p);
	unique_ptr<int>ptr2(p);

	cout<<"ptr1:"<<*ptr1<<endl;
	cout<<"ptr2:"<<*ptr2<<endl;
	cout<<"&ptr1:"<<ptr1<<endl;
	
	cout<<"&ptr1:"<<&ptr2<<endl;
}
	

