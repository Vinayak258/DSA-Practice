#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minScore(int n, vector<vector<int>> &roads)
    {
        vector<vector<pair<int, int>>> adj(n + 1);

        // Build graph
        for (auto &r : roads)
        {
            int u = r[0];
            int v = r[1];
            int w = r[2];

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        queue<int> q;
        vector<bool> vis(n + 1, false);

        q.push(1);
        vis[1] = true;

        int ans = INT_MAX;

        // BFS from city 1
        while (!q.empty())
        {
            int u = q.front();
            q.pop();

            for (auto &[v, w] : adj[u])
            {
                ans = min(ans, w);

                if (!vis[v])
                {
                    vis[v] = true;
                    q.push(v);
                }
            }
        }

        return ans;
    }
};

int main()
{
    int n, m;
    cin >> n >> m; // number of cities and roads

    vector<vector<int>> roads(m, vector<int>(3));

    for (int i = 0; i < m; i++)
    {
        cin >> roads[i][0] >> roads[i][1] >> roads[i][2];
    }

    Solution obj;
    cout << obj.minScore(n, roads) << endl;

    return 0;
}