#include<iostream>
using namespace std;
#include<map>
#include<string>
class test{
	public:
	int priority;
	string name;

	test(const string& s, int p) : name(s), priority(p){}
};

struct testComparator{
	bool operator () (const test &left, const test &right)const{
		if(left.priority != right.priority){
			return left.priority > right.priority;
		}
			return left.name < right.name;
	}
};


int main(){

	map<test, string, testComparator> mt;
	mt[test("task1", 3)] = "complete report";
	mt[test("task2", 5)] = "fix bugs";
	mt[test("task3", 6)] = "write tests";

	for(const auto &[x,y]: mt){
		cout<<x.name<<" , " << x.priority <<": "<<y<<endl;
	}
}

