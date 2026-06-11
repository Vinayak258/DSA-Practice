#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    static const int MOD = 1e9 + 7;

    long long modPow(long long a, long long b)
    {
        long long res = 1;
        while (b)
        {
            if (b & 1)
                res = (res * a) % MOD;
            a = (a * a) % MOD;
            b >>= 1;
        }
        return res;
    }

    int assignEdgeWeights(vector<vector<int>> &edges)
    {
        int n = edges.size() + 1;

        vector<vector<int>> adj(n + 1);
        for (auto &e : edges)
        {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        queue<pair<int, int>> q;
        vector<int> vis(n + 1, 0);

        q.push({1, 0});
        vis[1] = 1;

        int mxDepth = 0;

        while (!q.empty())
        {
            auto [u, d] = q.front();
            q.pop();

            mxDepth = max(mxDepth, d);

            for (int v : adj[u])
            {
                if (!vis[v])
                {
                    vis[v] = 1;
                    q.push({v, d + 1});
                }
            }
        }

        return modPow(2, mxDepth - 1);
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m; // number of edges = n - 1
    cin >> m;

    vector<vector<int>> edges(m, vector<int>(2));
    for (int i = 0; i < m; i++)
    {
        cin >> edges[i][0] >> edges[i][1];
    }

    Solution obj;
    cout << obj.assignEdgeWeights(edges) << '\n';

    return 0;
}