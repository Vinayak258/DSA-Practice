#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>> &invocations)
    {
        vector<vector<int>> adj(n);
        vector<int> suspicious(n, 0);

        // Build graph
        for (auto &edge : invocations)
        {
            adj[edge[0]].push_back(edge[1]);
        }

        // BFS to find all suspicious methods
        queue<int> q;
        q.push(k);
        suspicious[k] = 1;

        while (!q.empty())
        {
            int u = q.front();
            q.pop();

            for (int v : adj[u])
            {
                if (!suspicious[v])
                {
                    suspicious[v] = 1;
                    q.push(v);
                }
            }
        }

        // Check if any non-suspicious method calls a suspicious method
        for (auto &edge : invocations)
        {
            int u = edge[0];
            int v = edge[1];

            if (!suspicious[u] && suspicious[v])
            {
                vector<int> ans;
                for (int i = 0; i < n; i++)
                    ans.push_back(i);
                return ans;
            }
        }

        // Remove suspicious methods
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            if (!suspicious[i])
                ans.push_back(i);
        }

        return ans;
    }
};

int main()
{
    int n, k, m;

    cout << "Enter number of methods (n): ";
    cin >> n;

    cout << "Enter suspicious method (k): ";
    cin >> k;

    cout << "Enter number of invocations: ";
    cin >> m;

    vector<vector<int>> invocations(m, vector<int>(2));

    cout << "Enter each invocation (caller callee):\n";
    for (int i = 0; i < m; i++)
    {
        cin >> invocations[i][0] >> invocations[i][1];
    }

    Solution obj;
    vector<int> ans = obj.remainingMethods(n, k, invocations);

    cout << "Remaining Methods: ";
    for (int x : ans)
        cout << x << " ";
    cout << endl;

    return 0;
}