#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int n;
    vector<vector<int>> dp;

    bool solve(int i, int j, vector<vector<int>> &mat,
               vector<vector<int>> &ans)
    {

        if (i >= n || j >= n || mat[i][j] == 0)
            return false;

        if (i == n - 1 && j == n - 1)
        {
            ans[i][j] = 1;
            return true;
        }

        if (dp[i][j] != -1)
            return dp[i][j];

        ans[i][j] = 1;

        int jump = mat[i][j];

        for (int k = 1; k <= jump; k++)
        {

            // Move Right first
            if (j + k < n)
            {
                if (solve(i, j + k, mat, ans))
                    return dp[i][j] = 1;
            }

            // Move Down
            if (i + k < n)
            {
                if (solve(i + k, j, mat, ans))
                    return dp[i][j] = 1;
            }
        }

        ans[i][j] = 0; // Backtrack
        return dp[i][j] = 0;
    }

public:
    vector<vector<int>> shortestDist(vector<vector<int>> &mat)
    {
        n = mat.size();

        if (n == 0 || mat[0][0] == 0)
            return {{-1}};

        vector<vector<int>> ans(n, vector<int>(n, 0));
        dp.assign(n, vector<int>(n, -1));

        if (solve(0, 0, mat, ans))
            return ans;

        return {{-1}};
    }
};

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> mat(n, vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> mat[i][j];
        }
    }

    Solution obj;
    vector<vector<int>> result = obj.shortestDist(mat);

    for (auto &row : result)
    {
        for (int x : row)
        {
            cout << x << " ";
        }
        cout << "\n";
    }

    return 0;
}