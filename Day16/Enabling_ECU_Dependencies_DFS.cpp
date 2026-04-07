#include<iostream>
using namespace std;
#define MAX 5
int Graph[MAX][MAX];
bool visited[MAX]{false};

struct ECU{
	string name;
	bool status;
};

ECU Devices[MAX] ={{"EngineControl",false}, {"FuelSystem",false}, {"Ignition",false}, {"SensorModule",false}, {"LoggingSystem",false}};

void dfs(int node){
	visited[node] = true;
	Devices[node].status = true;
	cout<<"Activating " << Devices[node].name << " ,status: " <<Devices[node].status <<endl;
	for(int i=0; i<MAX; i++){
		if(Graph[node][i] == 1 && !visited[i]){
			dfs(i);
		}
	}	
}

int main(){
	Graph[0][1] = 1;
	Graph[0][2] = 1;
	Graph[1][3] = 1;
	Graph[2][3] = 1;
	Graph[3][4] = 1;
	dfs(0);

}
