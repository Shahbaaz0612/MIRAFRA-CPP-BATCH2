#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

struct Edge {
    string location;   
    int dest;          
    int weight;       

    Edge(string name, int d, int w)
        : location(name), dest(d), weight(w) {}
};

struct NodeState {
    int vertex;
    int distance;

    NodeState(int v, int d)
        : vertex(v), distance(d) {}
};

struct Compare {
    bool operator()(const NodeState& a, const NodeState& b) {
        return a.distance > b.distance; 
    }
};

class WeightedGraph {

    int V;
    vector<vector<Edge>> adj;
    vector<string> location;

public:

    WeightedGraph(int vertices) {
        V = vertices;
        adj.resize(V);
        location.resize(V);
    }

    void setLocation(int index, string name) {
        location[index] = name;
    }

    void addEdge(int u, int v, int weight) {
        adj[u].push_back(Edge(location[v], v, weight));
        adj[v].push_back(Edge(location[u], u, weight));
    }

    void shortestPath(int src) {
        priority_queue<NodeState, vector<NodeState>, Compare> pq;
        vector<int> dist(V, INT_MAX);
        vector<int> parent(V, -1);
        vector<bool> visited(V, false);
        dist[src] = 0;
        pq.push(NodeState(src, 0));

        while (!pq.empty()) {
            NodeState current = pq.top();
            pq.pop();
            int node = current.vertex;
            int d = current.distance;
            if (visited[node])
                continue;
            visited[node] = true;
            for (auto edge : adj[node]) {
                int neighbor = edge.dest;
                int weight = edge.weight;
                if (dist[neighbor] > d + weight) {
                    dist[neighbor] = d + weight;
                    parent[neighbor] = node;
                    pq.push(NodeState(neighbor, dist[neighbor]));
                }
            }
        }

        cout << "Shortest distances from source "
             << location[src] << ":\n";
        for (int i = 0; i < V; i++) {
            cout << "To " << location[i]
                 << " = " << dist[i];
            cout << endl;
        }
    }
};

int main() {

    WeightedGraph g(5);
    g.setLocation(0, "Home");
    g.setLocation(1, "School");
    g.setLocation(2, "Market");
    g.setLocation(3, "Hospital");
    g.setLocation(4, "Office");

    g.addEdge(0, 1, 4);
    g.addEdge(0, 2, 1);
    g.addEdge(2, 1, 2);
    g.addEdge(1, 3, 1);
    g.addEdge(2, 3, 5);
    g.addEdge(3, 4, 3);

    g.shortestPath(0);

    return 0;
}
