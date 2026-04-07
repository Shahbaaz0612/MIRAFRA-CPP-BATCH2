#include <iostream>
using namespace std;
#include <map>
#include <string>

int main() {
	map<string, int> stu_score;
	stu_score["shahbaaz"] = 92;
	stu_score["manohar"] = 90;
	stu_score.insert(make_pair("rakesh",95));
	stu_score["manohar"] = 95;//can modify..
	stu_score.insert(make_pair("rakesh",100));//can't modify..	
	stu_score.insert( {"rakesh", 100});//can't modify..

	for(auto &p: stu_score){
		cout<<p.first<<": "<<p.second<<endl;
	}

	if(stu_score.find("rakesh") != stu_score.end()){
		cout<<"rakesh found.."<<endl;
	}else{
		cout<<"rakesh not found.."<<endl;
	}

	if(stu_score.erase("shahbaaz")){
		cout<<"shahbaaz died.."<<endl;
	}else{
		cout<<"shahbaaz alive.."<<endl;
	}
	cout<<"manohar count: "<<stu_score.count("manohar")<<endl;
}


