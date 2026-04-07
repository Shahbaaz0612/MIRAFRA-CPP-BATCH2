#include<iostream>
using namespace std;
#include<list>
#include<unordered_map>

class GraphAdj{
	unordered_map<int, list<int>> adj;
	public:
	
	void addEdge(int u, int v, bool direction){
		adj[u].push_back(v);
		if(direction){
			adj[v].push_back(u);
		}
	}
	
	void display()const{
		for(const auto& map : adj){
			cout << map.first << " --> ";
			for(const auto& value : map.second){
				cout << value<< ",";

			}cout<<endl;
		}
	}
};


int main(){
	GraphAdj graph;
	bool direction = true;
	graph.addEdge(1, 2, direction);
	graph.addEdge(0, 3, direction);
	graph.addEdge(2, 0, direction);
	graph.addEdge(3, 1, direction);
	graph.display();
}
