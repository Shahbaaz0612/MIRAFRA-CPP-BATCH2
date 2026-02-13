#include<iostream>
using namespace std;
class A{
	public:
	static void fun(){}
};

int main(){

	void(*fp)(void) = A::fun;
	fp();

	int a=10;
 	namespace sha{
		int x=10;
		cout<<x<<endl;
	}
}
