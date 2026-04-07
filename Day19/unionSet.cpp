#include<iostream>
using namespace std;
#include<vector>

void printDSU(const vector<int>& parent, const vector<int>& rank){
	for(auto p : parent){
		cout<<p<<" ";
	}cout<<endl;
	for(auto r : rank){
		cout<<r<<" ";
	}cout<<endl;
	cout<<"------------------------"<<endl;
}

void makeSet(int v, vector<int>& parent, vector<int> &rank){
	for(int i=0; i<v; i++){
		parent[i] = i;
		rank[i] = 0;
	}
}

int findParent(vector<int>& parent, int node){
	if(node == parent[node]){
		return node;
	}
	return parent[node] = findParent(parent, parent[node]);
}

void unionSet(int u, int v,vector<int>& parent, vector<int>& rank){
	u = findParent(parent, u);
	v = findParent(parent, v);
	if(u == v){
		cout<<"nodes "<<u<<" and "<<v<<" are int the same set"<<endl;
		return;
	}
	if(rank[u] < rank[v]){
		parent[u] = v;
	}
	else if(rank[v] < rank[u]){
		parent[v] = u;
	}
	else{
		parent[v] = u;
		rank[u]++;
	}
	cout<<"union done between "<<u<<" and "<<v<<endl;
	printDSU(parent, rank);
}


int main(){

	int v= 7;
	vector<int> parent(v);
	vector<int> rank(v);
	makeSet(v, parent, rank);

	printDSU(parent,rank);

	unionSet(0, 1, parent, rank);
	unionSet(1, 2, parent, rank);
	unionSet(3, 4, parent, rank);
	unionSet(5, 6, parent, rank);
	unionSet(2, 6, parent, rank);
cout << "\nChecking connectivity:\n";

    if(findParent(parent, 0) == findParent(parent, 6)) // path compression
        cout << "0 and 6 are connected\n";
    else
        cout << "0 and 6 are NOT connected\n";

    if(findParent(parent, 3) == findParent(parent, 0))
        cout << "3 and 0 are connected\n";
    else
        cout << "3 and 0 are NOT connected\n";
}

