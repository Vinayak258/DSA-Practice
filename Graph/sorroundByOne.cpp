#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int n, m;

    // DFS to remove all boundary-connected 1s
    void dfs(int i, int j, vector<vector<int>> &grid)
    {

        // Check boundaries and invalid cells
        if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == 0)
            return;

        // Mark current cell as visited
        grid[i][j] = 0;

        // Move in 4 directions
        dfs(i + 1, j, grid);
        dfs(i - 1, j, grid);
        dfs(i, j + 1, grid);
        dfs(i, j - 1, grid);
    }

    int cntOnes(vector<vector<int>> &grid)
    {
        n = grid.size();
        m = grid[0].size();

        // Traverse first and last column
        for (int i = 0; i < n; i++)
        {
            if (grid[i][0] == 1)
                dfs(i, 0, grid);

            if (grid[i][m - 1] == 1)
                dfs(i, m - 1, grid);
        }

        // Traverse first and last row
        for (int j = 0; j < m; j++)
        {
            if (grid[0][j] == 1)
                dfs(0, j, grid);

            if (grid[n - 1][j] == 1)
                dfs(n - 1, j, grid);
        }

        // Count remaining enclosed 1s
        int count = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                    count++;
            }
        }

        return count;
    }
};

int main()
{

    vector<vector<int>> grid = {
        {0, 0, 0, 0},
        {1, 0, 1, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 0}};

    Solution obj;

    cout << obj.cntOnes(grid);

    return 0;
}