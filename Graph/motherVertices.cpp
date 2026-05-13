#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfs(int node, vector<vector<int>> &adj, vector<int> &vis)
    {
        vis[node] = 1;

        for (int nbr : adj[node])
        {
            if (!vis[nbr])
            {
                dfs(nbr, adj, vis);
            }
        }
    }

    int findMotherVertex(int V, vector<vector<int>> &edges)
    {

        // Create adjacency list
        vector<vector<int>> adj(V);

        for (auto &e : edges)
        {
            adj[e[0]].push_back(e[1]);
        }

        vector<int> vis(V, 0);

        int candidate = -1;

        // Step 1: Find potential mother vertex
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                dfs(i, adj, vis);
                candidate = i;
            }
        }

        // Step 2: Verify candidate
        fill(vis.begin(), vis.end(), 0);

        dfs(candidate, adj, vis);

        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                return -1;
            }
        }

        // Step 3: Find smallest mother vertex
        int ans = candidate;

        for (int i = 0; i < candidate; i++)
        {

            fill(vis.begin(), vis.end(), 0);

            dfs(i, adj, vis);

            bool allReachable = true;

            for (int j = 0; j < V; j++)
            {
                if (!vis[j])
                {
                    allReachable = false;
                    break;
                }
            }

            if (allReachable)
            {
                ans = i;
                break;
            }
        }

        return ans;
    }
};

int main()
{

    int V, E;
    cin >> V >> E;

    vector<vector<int>> edges;

    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;

        edges.push_back({u, v});
    }

    Solution obj;

    cout << obj.findMotherVertex(V, edges) << endl;

    return 0;
}