#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int m, n;
    vector<vector<bool>> visited;

    bool containsCycle(vector<vector<char>> &grid)
    {
        m = grid.size();
        n = grid[0].size();
        visited.assign(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!visited[i][j])
                {
                    if (dfs(grid, i, j, -1, -1))
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }

private:
    bool dfs(vector<vector<char>> &grid, int x, int y, int px, int py)
    {
        visited[x][y] = true;

        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};

        for (int d = 0; d < 4; d++)
        {
            int nx = x + dx[d];
            int ny = y + dy[d];

            // Boundary check
            if (nx < 0 || ny < 0 || nx >= m || ny >= n)
                continue;

            // Only move if same character
            if (grid[nx][ny] != grid[x][y])
                continue;

            if (!visited[nx][ny])
            {
                if (dfs(grid, nx, ny, x, y))
                    return true;
            }
            // If visited and not parent → cycle detected
            else if (nx != px || ny != py)
            {
                return true;
            }
        }

        return false;
    }
};

int main()
{
    Solution sol;

    // Example test case
    vector<vector<char>> grid = {
        {'a', 'a', 'a', 'a'},
        {'a', 'b', 'b', 'a'},
        {'a', 'b', 'b', 'a'},
        {'a', 'a', 'a', 'a'}};

    bool result = sol.containsCycle(grid);

    if (result)
    {
        cout << "Cycle detected\n";
    }
    else
    {
        cout << "No cycle\n";
    }

    return 0;
}