#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void dfs(int u, vector<vector<int>> &adj, vector<int> &vis,
             int &nodes, int &degSum)
    {
        vis[u] = 1;
        nodes++;
        degSum += adj[u].size();

        for (int v : adj[u])
        {
            if (!vis[v])
                dfs(v, adj, vis, nodes, degSum);
        }
    }

    int countCompleteComponents(int n, vector<vector<int>> &edges)
    {
        vector<vector<int>> adj(n);

        // Build graph
        for (auto &e : edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> vis(n, 0);
        int ans = 0;

        // Traverse each connected component
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                int nodes = 0;
                int degSum = 0;

                dfs(i, adj, vis, nodes, degSum);

                // Complete graph condition
                if (degSum == nodes * (nodes - 1))
                    ans++;
            }
        }

        return ans;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> edges(m, vector<int>(2));

    for (int i = 0; i < m; i++)
    {
        cin >> edges[i][0] >> edges[i][1];
    }

    Solution obj;
    cout << obj.countCompleteComponents(n, edges) << endl;

    return 0;
}