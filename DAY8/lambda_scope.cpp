#include<iostream>
using namespace std;
#include<functional>

int fun(auto fptr){
	cout<<fptr()<<endl;
}

int main(){
	std::function<int()>fptr;
	{
		int x=10;
		fptr = [&x] () {
			return x*10;
		};
	}
	fun(fptr);
	cout<<fptr()<<endl;//error generally...
}
