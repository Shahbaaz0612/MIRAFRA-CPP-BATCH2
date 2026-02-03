#include<iostream>
using namespace std;
#include<vector>

int main()
{
	vector<string>vect={"shahbaaz","manohar","rakesh"};

	for(const auto& v:vect){
		cout<<v<<endl;
	}
};
