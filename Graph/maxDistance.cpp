#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> maxDistance(int V, int src, vector<vector<int>> &edges)
    {

        // Adjacency list: u -> {v, weight}
        vector<vector<pair<int, int>>> adj(V);

        for (auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            adj[u].push_back({v, w});
        }

        // Calculate indegree of every vertex
        vector<int> indegree(V, 0);

        for (int u = 0; u < V; u++)
        {
            for (auto &[v, w] : adj[u])
            {
                indegree[v]++;
            }
        }

        // Topological Sort using Kahn's Algorithm
        queue<int> q;

        for (int i = 0; i < V; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }

        vector<int> topo;

        while (!q.empty())
        {
            int u = q.front();
            q.pop();

            topo.push_back(u);

            for (auto &[v, w] : adj[u])
            {
                indegree[v]--;

                if (indegree[v] == 0)
                {
                    q.push(v);
                }
            }
        }

        // Initialize distances
        vector<int> dist(V, INT_MIN);

        // Distance from source to itself
        dist[src] = 0;

        // Longest path DP
        for (int u : topo)
        {

            // If u is unreachable from source
            if (dist[u] == INT_MIN)
            {
                continue;
            }

            for (auto &[v, w] : adj[u])
            {
                dist[v] = max(dist[v], dist[u] + w);
            }
        }

        return dist;
    }
};

int main()
{

    int V, E;

    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    vector<vector<int>> edges(E, vector<int>(3));

    cout << "Enter edges (u v weight):\n";

    for (int i = 0; i < E; i++)
    {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }

    int src;

    cout << "Enter source vertex: ";
    cin >> src;

    Solution obj;

    vector<int> result = obj.maxDistance(V, src, edges);

    cout << "\nLongest distances from source " << src << ":\n";

    for (int i = 0; i < V; i++)
    {

        if (result[i] == INT_MIN)
        {
            cout << "INF";
        }
        else
        {
            cout << result[i];
        }

        if (i != V - 1)
        {
            cout << " ";
        }
    }

    cout << endl;

    return 0;
}