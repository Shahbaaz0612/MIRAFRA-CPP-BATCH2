#include<iostream>
using namespace std;
#include<vector>
#include<cstring>
#include<iomanip>
#include<limits>

template<class T>
class DirectedWeightGraph{
	int v;
	T INF;
	vector<vector<T>> matrix;

	public:
	DirectedWeightGraph(int vertex) : v(vertex), matrix(v, vector<T>(v,INF)), INF(numeric_limits<T>::max()) { }

	void addEdge(int src, int dest, T weight){
		if(src>=0 && src<v && dest>=0 && dest<v){
			matrix[src][dest] = weight;
		}
	}

	void display()const{
		for(const auto& row: matrix ){
			for(const auto& value: row){
				if(value == INF){
					cout<<std::setw(6)<< "$";
				}
				else 
				cout << std::setw(6) << value;
			}cout<<endl;
		}
	}
};

int main(){
	DirectedWeightGraph <int> graph(4);
	graph.addEdge(1,2,30);
	graph.addEdge(0,1,15);
	graph.addEdge(2,3,25);
	graph.addEdge(3,3,55);
	graph.display();cout<<endl;
	
/*	DirectedWeightGraph <chat> graph1(4);
	graph1.addEdge(1,2'A');
	graph1.addEdge(0,1,'B');
	graph1.addEdge(2,3,'C');
	graph1.addEdge(3,3,'D');
	graph1.display();cout<<endl;

*/
}

	


