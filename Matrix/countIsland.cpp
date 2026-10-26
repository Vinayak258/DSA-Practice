
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countIslands(vector<vector<int>> &grid, int k)
    {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;

        vector<vector<bool>> vis(m, vector<bool>(n, false));

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {

                if (grid[i][j] > 0 && !vis[i][j])
                {
                    long long sum = 0;
                    stack<pair<int, int>> st;

                    st.push({i, j});
                    vis[i][j] = true;

                    while (!st.empty())
                    {
                        auto [x, y] = st.top();
                        st.pop();

                        sum += grid[x][y];

                        for (int d = 0; d < 4; d++)
                        {
                            int nx = x + dx[d];
                            int ny = y + dy[d];

                            if (nx >= 0 && nx < m &&
                                ny >= 0 && ny < n &&
                                grid[nx][ny] > 0 &&
                                !vis[nx][ny])
                            {

                                vis[nx][ny] = true;
                                st.push({nx, ny});
                            }
                        }
                    }

                    if (sum % k == 0)
                    {
                        ans++;
                    }
                }
            }
        }

        return ans;
    }
};

int main()
{
    Solution sol;

    // Example 1
    vector<vector<int>> grid1 = {
        {0, 2, 1, 0, 0},
        {0, 5, 0, 0, 5},
        {0, 0, 1, 0, 0},
        {0, 1, 4, 7, 0},
        {0, 2, 0, 0, 8}};

    int k1 = 5;
    cout << sol.countIslands(grid1, k1) << endl;

    // Example 2
    vector<vector<int>> grid2 = {
        {3, 0, 3, 0},
        {0, 3, 0, 3},
        {3, 0, 3, 0}};

    int k2 = 3;
    cout << sol.countIslands(grid2, k2) << endl;

    return 0;
}
