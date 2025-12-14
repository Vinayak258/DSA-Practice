#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> prefixSum2D(vector<vector<int>> &mat, vector<vector<int>> &queries)
    {
        int n = mat.size();
        int m = mat[0].size();

        // Prefix sum matrix
        vector<vector<int>> ps(n, vector<int>(m, 0));

        // Build prefix sum
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                ps[i][j] = mat[i][j];
                if (i > 0)
                    ps[i][j] += ps[i - 1][j];
                if (j > 0)
                    ps[i][j] += ps[i][j - 1];
                if (i > 0 && j > 0)
                    ps[i][j] -= ps[i - 1][j - 1];
            }
        }

        // Process queries
        vector<int> ans;
        for (auto &q : queries)
        {
            int r1 = q[0], c1 = q[1], r2 = q[2], c2 = q[3];

            int sum = ps[r2][c2];
            if (r1 > 0)
                sum -= ps[r1 - 1][c2];
            if (c1 > 0)
                sum -= ps[r2][c1 - 1];
            if (r1 > 0 && c1 > 0)
                sum += ps[r1 - 1][c1 - 1];

            ans.push_back(sum);
        }

        return ans;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> mat(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mat[i][j];
        }
    }

    int q;
    cin >> q;

    vector<vector<int>> queries(q, vector<int>(4));
    for (int i = 0; i < q; i++)
    {
        cin >> queries[i][0] >> queries[i][1] >> queries[i][2] >> queries[i][3];
    }

    Solution obj;
    vector<int> result = obj.prefixSum2D(mat, queries);

    for (int x : result)
    {
        cout << x << " ";
    }
    cout << "\n";

    return 0;
}
