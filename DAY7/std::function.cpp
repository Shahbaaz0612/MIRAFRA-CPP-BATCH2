#include<iostream>
using namespace std;
#include<functional>

//normal function...
int add(int a, int b){
	return a+b;
}

//functor...
class functor{ 
	public:
		int operator () (int a, int b){
			return a+b;
		}
};

int main()
{
	function<int(int,int)> f; //std::function declaration...
       	
	//lambda function...
	f = [](int a, int b) {
		return a+b;
	};
	cout<<"Sum: "<<f(5,7)<<endl;
	
	f=add;
	cout<<f(2,3)<<endl;
	
	f=functor{};
	cout<<f(2,3)<<endl;
	
	return 0;
}
