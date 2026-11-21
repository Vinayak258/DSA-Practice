
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findSubtreeSizes(vector<int> &parent, string s)
    {
        int n = parent.size();

        vector<vector<int>> adj(n), newAdj(n);

        // Build original tree
        for (int i = 1; i < n; i++)
        {
            adj[parent[i]].push_back(i);
        }

        vector<int> last(26, -1);
        vector<int> newParent(n, -1);

        // First DFS: Find closest matching ancestor
        function<void(int)> dfs = [&](int u)
        {
            int ch = s[u] - 'a';
            int prev = last[ch];

            newParent[u] = (prev != -1) ? prev : parent[u];

            last[ch] = u;

            for (int v : adj[u])
            {
                dfs(v);
            }

            last[ch] = prev;
        };

        dfs(0);

        // Build modified tree
        for (int i = 1; i < n; i++)
        {
            newAdj[newParent[i]].push_back(i);
        }

        vector<int> ans(n, 1);

        // Second DFS: Calculate subtree sizes
        function<void(int)> dfs2 = [&](int u)
        {
            for (int v : newAdj[u])
            {
                dfs2(v);
                ans[u] += ans[v];
            }
        };

        dfs2(0);

        return ans;
    }
};

int main()
{
    int n;
    cin >> n;

    vector<int> parent(n);

    for (int i = 0; i < n; i++)
    {
        cin >> parent[i];
    }

    string s;
    cin >> s;

    Solution obj;

    vector<int> ans = obj.findSubtreeSizes(parent, s);

    for (int x : ans)
    {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}
