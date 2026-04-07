#include<iostream>
using namespace std;
#include<queue>

class task{
	public:
	string process_name;
	int priority;
	int tid;

	task(string s, int p, int t) : process_name(s), priority(p), tid(t){}

	friend ostream& operator << (ostream& os, const task& Task) {
		os<<"task: "<< Task.process_name << " priority: "<< Task.priority <<"task ID: "<<Task.tid;
		return os;
	}

};

struct compareTask{
	bool operator() (const task& left, const task& right){
		if(left.priority == right.priority){
			return (left.tid < right.tid);
		}
		return left.priority < right.priority;
	}
};

int main(){

	priority_queue<task, vector<task>, compareTask> taskQueue; 
	taskQueue.push( task("task1",1,5) );
	taskQueue.push( task("task2",3,10) );



}
