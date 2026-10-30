#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int shortestPath(int n, vector<vector<int>> &edges, string labels, int k)
    {
        using ll = long long;
        const ll INF = LLONG_MAX / 4;

        // Build directed graph
        vector<vector<pair<int, int>>> adj(n);

        for (auto &e : edges)
        {
            int u = e[0];
            int v = e[1];
            int w = e[2];

            adj[u].push_back({v, w});
        }

        // dist[node][cnt] stores minimum cost to reach node
        // with cnt consecutive occurrences of its label.
        vector<vector<ll>> dist(n, vector<ll>(k + 1, INF));

        // {cost, node, consecutive count}
        using State = tuple<ll, int, int>;

        priority_queue<State, vector<State>, greater<State>> pq;

        // Starting node has one occurrence of its label.
        dist[0][1] = 0;
        pq.push({0, 0, 1});

        while (!pq.empty())
        {
            auto [cost, u, cnt] = pq.top();
            pq.pop();

            if (cost != dist[u][cnt])
            {
                continue;
            }

            // First valid destination state popped is optimal.
            if (u == n - 1)
            {
                return (int)cost;
            }

            for (auto &[v, w] : adj[u])
            {
                int newCnt;

                if (labels[u] == labels[v])
                {
                    newCnt = cnt + 1;
                }
                else
                {
                    newCnt = 1;
                }

                // Skip invalid paths.
                if (newCnt > k)
                {
                    continue;
                }

                ll newCost = cost + w;

                if (newCost < dist[v][newCnt])
                {
                    dist[v][newCnt] = newCost;
                    pq.push({newCost, v, newCnt});
                }
            }
        }

        return -1;
    }
};

int main()
{
    int n, m, k;
    cin >> n >> m;

    vector<vector<int>> edges(m, vector<int>(3));

    for (int i = 0; i < m; i++)
    {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }

    string labels;
    cin >> labels;

    cin >> k;

    Solution sol;

    cout << sol.shortestPath(n, edges, labels, k) << endl;

    return 0;
}