#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <queue>
#include <climits>
using namespace std;

vector<pair<pair<int,int>, int>> calculatePrimsMST(
        int n,
        vector<pair<pair<int,int>, int>> &g)
{
    unordered_map<int, list<pair<int,int>>> adj;

    for (auto edge : g)
    {
        int u = edge.first.first;
        int v = edge.first.second;
        int w = edge.second;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<int> key(n + 1, INT_MAX);
    vector<bool> visited(n + 1, false);
    vector<int> parent(n + 1, -1);

    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    > pq;

    key[1] = 0;
    pq.push({0, 1});
    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        if (visited[u])
            continue;
        visited[u] = true;
        for (auto neighbour : adj[u])
        {
            int v = neighbour.first;
            int weight = neighbour.second;
            if (!visited[v] && weight < key[v])
            {
                key[v] = weight;
                parent[v] = u;
                pq.push({key[v], v});                                                                                                                                                                                             }
        }
    }
    vector<pair<pair<int,int>, int>> result;
    for (int i = 2; i <= n; i++)
    {
        result.push_back({{parent[i], i}, key[i]});
    }
    return result;
}


int main()
{
    int n = 6;
    vector<pair<pair<int,int>, int>> edges = {
        {{1,2}, 3},
        {{1,3}, 4},
        {{2,3}, 2},
        {{2,4}, 6},
        {{3,4}, 5},
        {{3,5}, 7},
        {{4,6}, 4},
        {{5,6}, 3}
    };
    auto mst = calculatePrimsMST(n, edges);
    cout << "Optimized CAN Bus Cable Layout (MST):"<<endl<<endl;
    int totalCost = 0;
    for (auto edge : mst)
    {
        cout << "ECU "
             << edge.first.first << " - ECU "
             << edge.first.second
             << "   Cable Length: "
             << edge.second << " meters"<<endl;
        totalCost += edge.second;
    }
    cout << endl<<"Total Minimum Cable Required: "
         << totalCost << " meters"<<endl;
    return 0;
}


