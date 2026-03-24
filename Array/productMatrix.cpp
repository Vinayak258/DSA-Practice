#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        int mod = 12345;

        int size = n * m;
        vector<int> arr;

        // Flatten grid
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                arr.push_back(grid[i][j] % mod);
            }
        }

        // Prefix product
        vector<int> prefix(size, 1);
        for (int i = 1; i < size; i++)
        {
            prefix[i] = (1LL * prefix[i - 1] * arr[i - 1]) % mod;
        }

        // Build result using suffix
        vector<int> result(size);
        int suffix = 1;

        for (int i = size - 1; i >= 0; i--)
        {
            result[i] = (1LL * prefix[i] * suffix) % mod;
            suffix = (1LL * suffix * arr[i]) % mod;
        }

        // Convert back to 2D
        vector<vector<int>> ans(n, vector<int>(m));
        int k = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                ans[i][j] = result[k++];
            }
        }

        return ans;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));

    // Input
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }

    Solution obj;
    vector<vector<int>> ans = obj.constructProductMatrix(grid);

    // Output
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}