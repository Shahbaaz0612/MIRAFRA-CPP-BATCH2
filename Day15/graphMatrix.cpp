#include<iostream>
using namespace std;
#include<vector>

class graphMatrix{
	int v;
	vector<vector<int>> matrix;
	public:

	graphMatrix(int V) : v(V){
		matrix.resize(v,vector<int>(v,0));
	
	}

	void addEdge(int i, int j){
		matrix[i][j] = 1;
	//	matrix[j][i] = 1;
	}

	void print()const{
		for(int i=0; i<v; i++){
			for(int j=0; j<4; j++){
				cout<<matrix[i][j]<<" ";
			}
			cout<<endl;
		}
	}

};

int main(){
	graphMatrix obj(4);
	obj.print();cout<<endl;
	obj.addEdge(0,1);
	obj.addEdge(2,1);
	obj.addEdge(1,3);
	obj.print();

}
