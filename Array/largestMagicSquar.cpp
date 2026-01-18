#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int largestMagicSquare(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> row(m, vector<int>(n + 1, 0));
        vector<vector<int>> col(m + 1, vector<int>(n, 0));
        vector<vector<int>> diag1(m + 1, vector<int>(n + 1, 0));
        vector<vector<int>> diag2(m + 1, vector<int>(n + 2, 0));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                row[i][j + 1] = row[i][j] + grid[i][j];
                col[i + 1][j] = col[i][j] + grid[i][j];
                diag1[i + 1][j + 1] = diag1[i][j] + grid[i][j];
                diag2[i + 1][j] = diag2[i][j + 1] + grid[i][j];
            }
        }

        int ans = 1;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {

                for (int k = 2; i + k <= m && j + k <= n; k++)
                {

                    int target = row[i][j + k] - row[i][j];
                    bool ok = true;

                    // check rows
                    for (int r = i; r < i + k; r++)
                    {
                        if (row[r][j + k] - row[r][j] != target)
                        {
                            ok = false;
                            break;
                        }
                    }

                    // check columns
                    for (int c = j; c < j + k && ok; c++)
                    {
                        if (col[i + k][c] - col[i][c] != target)
                        {
                            ok = false;
                            break;
                        }
                    }

                    if (!ok)
                        continue;

                    // main diagonal
                    int d1 = diag1[i + k][j + k] - diag1[i][j];
                    if (d1 != target)
                        continue;

                    // anti diagonal
                    int d2 = diag2[i + k][j] - diag2[i][j + k];
                    if (d2 != target)
                        continue;

                    ans = max(ans, k);
                }
            }
        }

        return ans;
    }
};

int main()
{
    vector<vector<int>> grid = {
        {7, 1, 4, 5, 6},
        {2, 5, 1, 6, 4},
        {1, 5, 4, 3, 2},
        {1, 2, 7, 3, 4}};

    Solution sol;
    cout << sol.largestMagicSquare(grid);

    return 0;
}
