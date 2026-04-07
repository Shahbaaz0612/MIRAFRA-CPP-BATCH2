#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Station {
    int u;     // source
    int v;     // destination
    int wt;    // weight
};

void makeSet(vector<int> &parent, vector<int> &rank, int n)
{
    for(int i = 0; i < n; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }
}

int findParent(vector<int> &parent, int node)
{
    if(parent[node] == node)
        return node;

    return parent[node] = findParent(parent, parent[node]);
}

void unionSet(int u, int v, vector<int> &parent, vector<int> &rank)
{
    u = findParent(parent, u);
    v = findParent(parent, v);

    if(u == v)
        return;

    if(rank[u] < rank[v])
        parent[u] = v;
    else if(rank[v] < rank[u])
        parent[v] = u;
    else
    {
        parent[v] = u;
        rank[u]++;
    }
}

bool compare(const Station &src, const Station &dest)
{
    return src.wt < dest.wt;
}

int MST(vector<Station> &edges, int n)
{
    sort(edges.begin(), edges.end(), compare);

    vector<int> parent(n);
    vector<int> rank(n);
    makeSet(parent, rank, n);

    int minCost = 0;
    int edgeCount = 0;
    cout << "Stations Path in the fiber-Network-Design:"<<endl;
    for(const Station &e : edges)
    {
        int u = e.u;
        int v = e.v;
        int cost = e.wt;

        if(findParent(parent, u) != findParent(parent, v))
        {
            unionSet(u, v, parent, rank);
            cout << u << " - " << v << " : " << cost << endl;
            minCost += cost;
            edgeCount++;
            if(edgeCount == n - 1)
                break;
        }
    }
    return minCost;
}

int main()
{
    int n = 6;
    vector<Station> NetworkDesign = { 
        {0, 1, 4},
        {0, 2, 4},
        {1, 2, 2},
        {2, 3, 3},
        {2, 5, 2},
        {2, 4, 4},
        {3, 4, 3},
        {5, 4, 3}
    };
    int totalCost = MST(NetworkDesign, n);
    cout << "Total Fiber-Network-Design with minimum Cost: " << totalCost <<" Lakhs"<< endl;
    return 0;
}
