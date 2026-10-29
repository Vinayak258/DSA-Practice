
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<bool> palindromePath(int n, vector<vector<int>> &edges,
                                string s, vector<string> &queries)
    {

        vector<vector<int>> adj(n);

        for (auto &e : edges)
        {
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int LOG = 1;
        while ((1 << LOG) <= n)
        {
            LOG++;
        }

        vector<vector<int>> up(LOG, vector<int>(n));
        vector<int> parent(n, -1);
        vector<int> depth(n, 0);
        vector<int> tin(n), tout(n);
        vector<int> basePrefix(n, 0);

        int timer = 0;

        // Iterative DFS
        vector<pair<int, int>> st;

        parent[0] = 0;
        tin[0] = timer++;

        st.push_back({0, 0});

        while (!st.empty())
        {
            int u = st.back().first;
            int &idx = st.back().second;

            if (idx < (int)adj[u].size())
            {
                int v = adj[u][idx++];

                if (v == parent[u])
                {
                    continue;
                }

                parent[v] = u;
                depth[v] = depth[u] + 1;

                basePrefix[v] =
                    basePrefix[u] ^ (1 << (s[v] - 'a'));

                tin[v] = timer++;

                st.push_back({v, 0});
            }
            else
            {
                tout[u] = timer - 1;
                st.pop_back();
            }
        }

        // Binary Lifting preprocessing
        for (int i = 0; i < n; i++)
        {
            up[0][i] = parent[i];
        }

        for (int j = 1; j < LOG; j++)
        {
            for (int i = 0; i < n; i++)
            {
                up[j][i] =
                    up[j - 1][up[j - 1][i]];
            }
        }

        // LCA function
        auto lca = [&](int u, int v)
        {
            if (depth[u] < depth[v])
            {
                swap(u, v);
            }

            int diff = depth[u] - depth[v];

            for (int j = 0; j < LOG; j++)
            {
                if (diff & (1 << j))
                {
                    u = up[j][u];
                }
            }

            if (u == v)
            {
                return u;
            }

            for (int j = LOG - 1; j >= 0; j--)
            {
                if (up[j][u] != up[j][v])
                {
                    u = up[j][u];
                    v = up[j][v];
                }
            }

            return parent[u];
        };

        // Fenwick Tree for XOR
        vector<int> bit(n + 2, 0);

        auto updateBIT = [&](int idx, int val)
        {
            while (idx <= n + 1)
            {
                bit[idx] ^= val;
                idx += idx & -idx;
            }
        };

        // Range XOR update [l, r]
        auto rangeUpdate = [&](int l, int r, int val)
        {
            updateBIT(l + 1, val);
            updateBIT(r + 2, val);
        };

        // Point XOR query
        auto pointQuery = [&](int idx)
        {
            int result = 0;
            idx++;

            while (idx > 0)
            {
                result ^= bit[idx];
                idx -= idx & -idx;
            }

            return result;
        };

        // Root-to-node prefix mask
        auto getPrefix = [&](int u)
        {
            return basePrefix[u] ^ pointQuery(tin[u]);
        };

        vector<bool> answer;

        for (string &q : queries)
        {
            stringstream ss(q);

            string type;
            ss >> type;

            if (type == "update")
            {
                int u;
                char c;

                ss >> u >> c;

                int oldMask = 1 << (s[u] - 'a');
                int newMask = 1 << (c - 'a');

                int delta = oldMask ^ newMask;

                rangeUpdate(tin[u], tout[u], delta);

                s[u] = c;
            }
            else
            {
                int u, v;
                ss >> u >> v;

                int ancestor = lca(u, v);

                int pathMask =
                    getPrefix(u) ^
                    getPrefix(v) ^
                    (1 << (s[ancestor] - 'a'));

                answer.push_back(
                    (pathMask & (pathMask - 1)) == 0);
            }
        }

        return answer;
    }
};

// Main function for testing
int main()
{
    int n = 3;

    vector<vector<int>> edges = {
        {0, 1},
        {1, 2}};

    string s = "aac";

    vector<string> queries = {
        "query 0 2",
        "update 1 b",
        "query 0 2"};

    Solution obj;

    vector<bool> result =
        obj.palindromePath(n, edges, s, queries);

    cout << "[";

    for (int i = 0; i < (int)result.size(); i++)
    {
        cout << (result[i] ? "true" : "false");

        if (i + 1 < (int)result.size())
        {
            cout << ", ";
        }
    }

    cout << "]" << endl;

    return 0;
}
