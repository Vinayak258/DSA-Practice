#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool hasValidPath(vector<vector<char>> &grid)
    {

        int m = grid.size();
        int n = grid[0].size();

        // Length of every possible path
        int len = m + n - 1;

        // Valid parentheses string must have even length
        if (len % 2 == 1)
            return false;

        // dp[i][j][balance]
        // true = possible to reach (i,j)
        // with the given balance
        vector<vector<vector<bool>>> dp(
            m,
            vector<vector<bool>>(
                n,
                vector<bool>(len + 1, false)));

        // Starting cell must be '('
        if (grid[0][0] == '(')
        {
            dp[0][0][1] = true;
        }
        else
        {
            return false;
        }

        // Traverse the grid
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {

                // Starting cell already handled
                if (i == 0 && j == 0)
                    continue;

                for (int balance = 0; balance <= len; balance++)
                {

                    int newBalance;

                    // Current cell contains '('
                    if (grid[i][j] == '(')
                    {
                        newBalance = balance + 1;
                    }
                    // Current cell contains ')'
                    else
                    {
                        newBalance = balance - 1;
                    }

                    // Invalid balance
                    if (newBalance < 0 || newBalance > len)
                        continue;

                    // Come from top
                    if (i > 0 && dp[i - 1][j][balance])
                    {
                        dp[i][j][newBalance] = true;
                    }

                    // Come from left
                    if (j > 0 && dp[i][j - 1][balance])
                    {
                        dp[i][j][newBalance] = true;
                    }
                }
            }
        }

        // At the last cell, balance must be 0
        return dp[m - 1][n - 1][0];
    }
};

int main()
{

    Solution sol;

    // Example 1
    vector<vector<char>> grid = {
        {'(', '(', '('},
        {')', '(', ')'},
        {'(', '(', ')'},
        {'(', '(', ')'}};

    bool ans = sol.hasValidPath(grid);

    if (ans)
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}