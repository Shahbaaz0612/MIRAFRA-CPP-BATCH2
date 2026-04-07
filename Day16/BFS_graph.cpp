#include<iostream>
using namespace std;
#include<vector>
#include<queue>

void bfs(int start, vector<vector<int>>& adj){
	int v = adj.size();
	vector<bool> visited(v,false);
      	queue<int>q;
       	visited[start] = true;
	q.push(start);
 	while(!q.empty()){
		int node = q.front();
		q.pop();
		cout<<node<<"";
		for(int neighbour : adj[node]){
			if(!visited[neighbour])	{
				visited[neighbour] = true;
				q.push(neighbour);
			}
		}
	}
}


int main(){
	int v =5;
	vector<vector<int>> adj[v];
	adj[0] = {1,2};
	adj[1] = {0,3};
	adj[2] = {0,4};
	adj[3] = {1};
	adj[4] = {2};

	cout<<"BFS traversal: ";
	bfs(0, adj);
	return 0;
}

