#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> shiftGrid(vector<vector<int>> &grid, int k)
    {
        int m = grid.size();
        int n = grid[0].size();
        int total = m * n;

        k %= total;

        vector<vector<int>> ans(m, vector<int>(n));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int idx = i * n + j;
                int newIdx = (idx + k) % total;

                ans[newIdx / n][newIdx % n] = grid[i][j];
            }
        }

        return ans;
    }
};

int main()
{
    int m, n, k;

    cout << "Enter number of rows and columns: ";
    cin >> m >> n;

    vector<vector<int>> grid(m, vector<int>(n));

    cout << "Enter grid elements:\n";
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }

    cout << "Enter k: ";
    cin >> k;

    Solution obj;
    vector<vector<int>> result = obj.shiftGrid(grid, k);

    cout << "\nShifted Grid:\n";
    for (auto &row : result)
    {
        for (auto &x : row)
        {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}