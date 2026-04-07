#include<iostream>
using namespace std;
#include<queue>

int main(){
	priority_queue<int> pq;
	priority_queue<int, vector<int>, greater<int>> pq1;
	pq.push(20);
	pq.push(30);
	pq.push(10);
	while(!pq.empty()){
		cout<<"top element: "<<pq.top() <<endl;
		pq.pop();
	}
	
	pq1.push(20);
	pq1.push(30);
	pq1.push(10);
	while(!pq1.empty()){
		cout<<"top element: "<<pq1.top() <<endl;
		pq1.pop();
	}
}
