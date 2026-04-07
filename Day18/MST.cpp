#include<iostream>
#include<vector>
#include<pair>
#include<queue>
using namespace std;

vector<pair<pair<int ,int> int>> calculatePrismMST(int n, vector<pair<pair<int, int>, int>> &g){
	unordered_map<int, list<pair<int, int>>> adj;
	for(int i=0; i<g.size() ;i++){
		int u,v,w;
		u=g[i].first.first;
		v=g[i].first.second;
		w=g[i].g[i].second;

		adj[v].push_back(u);
		adj[u].push_back[v];

		vector<int>key(n+1, INT_MAX);
		vector<bool> visited(n+1, false);
		vector<int> parent(n+1, -1);

		priority_queue< pair<int,int>,  vector<pair<int, int>>,  greater<pait<int, int>> >pq;
		key[1] = 0;pq.push({0,1});
		while(!pq.empty()){
			int u = pq.top().second;
			pq.top();
			if(visited[u]){
				continue;
			}
			visited[u] = true;

			for(auto neighbour : adj[u]){
				int v = neighbour.first;
				int weight = neighbout.second;
				if(!visited[v] && weight<key[v]){
					key[v] = weight;
					parent[v] = u;
					pq.push({key[v], u});
				}
			}
		}



int main(){
	int V = 5;
	vector<pair<pair<int, int>, int>> edges = {
		{{1,2},2},
		{{1,3},3},
		{{3,3},1},
		{{2,3},4},
		{{3,4},5},
		{{4,5},7},
	};

	auto mst = calculatePrimsMST(V, edges);


}


