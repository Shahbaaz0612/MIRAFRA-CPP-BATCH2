#include<iostream>
using namespace std;

void test(int v){
	
	if(v==0){
		cout<<"base reached.."<<endl;
		return;
	}
	cout << "entering test(" << v <<")" << endl;
	test(v-1);
	cout<<"returning from test("<< v << ")" <<endl;
}

int main(){

	int n=3;
	test(3);
}
	


