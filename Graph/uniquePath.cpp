
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    static const int MOD = 1e9 + 7;

    int uniquePaths(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dpR(m, vector<int>(n, 0));
        vector<vector<int>> dpD(m, vector<int>(n, 0));

        // Initial moves from the starting cell
        if (n > 1)
            dpR[0][1] = 1;

        if (m > 1)
            dpD[1][0] = 1;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {

                int fromRight = dpR[i][j];
                int fromDown = dpD[i][j];

                if (grid[i][j] == 0)
                {
                    // Empty cell: continue in either direction
                    int ways = (fromRight + fromDown) % MOD;

                    if (j + 1 < n)
                    {
                        dpR[i][j + 1] =
                            (dpR[i][j + 1] + ways) % MOD;
                    }

                    if (i + 1 < m)
                    {
                        dpD[i + 1][j] =
                            (dpD[i + 1][j] + ways) % MOD;
                    }
                }
                else
                {
                    // Mirror: right -> down
                    if (i + 1 < m)
                    {
                        dpD[i + 1][j] =
                            (dpD[i + 1][j] + fromRight) % MOD;
                    }

                    // Mirror: down -> right
                    if (j + 1 < n)
                    {
                        dpR[i][j + 1] =
                            (dpR[i][j + 1] + fromDown) % MOD;
                    }
                }
            }
        }

        return (dpR[m - 1][n - 1] + dpD[m - 1][n - 1]) % MOD;
    }
};
