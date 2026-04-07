#include<iostream>
using namespace std;
#include<queue>
struct process{
	int  id;
	int burst_time;
};

int main(){
	queue<process> qobj;
	qobj.push({1,5});
	qobj.push({2,4});
	qobj.push({3,10});

	int curr_time = 0;

	while(!qobj.empty()){
		process p = qobj.front();
		qobj.pop();

		cout<< "executing process Pid: " << p.id <<" from time "<< curr_time;
		curr_time += p.burst_time;
		cout<< " to " <<curr_time<<endl;
	}
}
