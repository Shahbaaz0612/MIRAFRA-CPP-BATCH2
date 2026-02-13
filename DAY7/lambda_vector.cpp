#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>
int main()
{
	vector<int>vec = {1,2,3};

	cout<<"printing vector elements"<<endl;
	for_each(vec.begin(), vec.end(), [] (auto value)
			{
				cout<<value<<" ";
			} );cout<<endl;
}
