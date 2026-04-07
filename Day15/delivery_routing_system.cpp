#include<iostream>
using namespace std;
#include<unordered_map>
#include<list>
#include<vector>

class RoutingSystem{
	unordered_map<string, vector<pair<string, double>>> route;
	public:
	void CreateRoute(const string& src, const string& dest, double time){
		route[src].push_back({dest, time});
		route[dest].push_back({src, time});
	}

	void displayRoutes(){
		for(const auto& src : route){
			cout<<src.first<< " ---> ";
			for(const auto& dest : src.second){
				cout<<dest.first<<"(";
				cout<<dest.second<<")kms, ";
			}
			cout<<endl<<endl;
		}
	}
	void findNeighbour(const string& src) {
		if(route.find(src) == route.end()){
			cout<<"No matches found"<<endl;
			return;
		}	
			double minDist = route[src][0].second;
			string neighbour = route[src][0].first;
			for(const auto& neighbourDist : route[src]){
				if(minDist > neighbourDist.second){
					minDist = neighbourDist.second;
					neighbour = neighbourDist.first;
				}
			}
			cout << src << " ---> " << neighbour << "(" << minDist << ")kms" << endl; 
	}

};


int main(){
	RoutingSystem path;
	path.CreateRoute("Mirafra", "CyberTower", 1);
	path.CreateRoute("Mirafra", "Western_Pearl", 0.7);
	path.CreateRoute("CyberTower", "Raidurg_Metro", 1.5);
	path.CreateRoute("Raidurg_Metro", "Western_Aqua", 2);
	path.CreateRoute("Mirafra", "Western_Aqua", 0.5);
	path.CreateRoute("AMB_Cinemas", "Western_Pearl", 1.5);
	path.CreateRoute("AMB_Cinemas", "Western_Aqua", 2);
	path.CreateRoute("AMB_Cinemas", "Cafe_Niloufer", 7);
	path.CreateRoute("Raidurg_Metro", "Cafe_Niloufer", 1.6);
	path.displayRoutes();
	string source;
	cout<<"Enter the Source name to find the nearest Neighbour: ";
	cin>>source;
	path.findNeighbour(source);
}


