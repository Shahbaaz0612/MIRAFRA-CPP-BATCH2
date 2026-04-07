#include<iostream>
using namespace std;
#include<vector>

void addEdge(int u, int v, vector<vector<int>>& adj){
	adj[u].push_back(v);
	adj[v].push_back(u);
}

bool dfs(int node, int parent, vector<vector<int>>& adj, vector<bool>& visited){
	visited[node]= true;
	for(int neighbor : adj[node]){
		if(!visited[neighbor]){
			if(dfs(neighbor, node, adj, visited)){
				return true;
			}
		}
		else if(neighbor != parent){
			return true;
		}
	}
	return false;
}

int main(){
	int v = 5;
	vector<vector<int>> adj(v);
	addEdge(1,2,adj);
	addEdge(2,3,adj);
	addEdge(3,4,adj);
	//addEdge(4,1,adj);
	
	vector<bool> visited(v,false);
	bool cycle_exist = false;
	for(int i=1; i<v; i++){
		if(!visited[i]){
			if(dfs(i, -1, adj, visited)){
				cycle_exist = true;
				break;
			}
		}
	}
	if(cycle_exist){
		cout<<"cycle detected"<<endl;
	}
	else{
		cout<<"no cycle detected"<<endl;
	}	
}



