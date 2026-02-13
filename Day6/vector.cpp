#include<iostream>
using namespace std;
#include<vector>
int main()
{
	vector<int >vec={1,2,3,4};
	vec.push_back(5);
	vec.emplace_back(6);
	vector<int> :: iterator it;
	for(it=vec.begin(); it!=vec.end(); it++){
		cout<<*(it)<<" ";
	}cout<<endl;

	cout<<"size of vec: "<<vec.size()<<endl;
	vec.reserve(10);
	cout<<"capacity: "<<vec.capacity()<<endl;
	vec.shrink_to_fit();//reduce the no.of elements to size of elements..
	cout<<"capacity: "<<vec.capacity()<<endl;


}

