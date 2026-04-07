#include<iostream>
using namespace std;
#include<queue>

struct process{
	int id;
	int time;
	int remainingTime;
};

int main(){
	queue<process> q;
	int timeQuantum = 2;
	int currentTime=0;
	q.push({1,5,5});
	q.push({2,3,3});
	q.push({3,6,6});

	while(!q.empty()){
		process p = q.front();
		q.pop();
		cout << "Executing p with pid: " << p.id << " at time: " << currentTime;	
		if(p.remainingTime > timeQuantum){
			p.remainingTime-=timeQuantum;
			currentTime+=timeQuantum;
			cout<< " for "<< timeQuantum << "units" << endl;
			q.push(p);
		}
		else{
			currentTime+=p.remainingTime;
			cout<<" for " << p.remainingTime << "units(Finished)" << endl;
			p.remainingTime = 0;
		}
	}
}
	
