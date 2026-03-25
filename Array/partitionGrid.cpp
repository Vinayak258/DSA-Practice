#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canPartitionGrid(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();

        vector<long long> rowSum(m, 0), colSum(n, 0);
        long long total = 0;

        // Compute row sums, column sums, and total sum
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                rowSum[i] += grid[i][j];
                colSum[j] += grid[i][j];
                total += grid[i][j];
            }
        }

        // If total sum is odd → cannot partition
        if (total % 2 != 0)
            return false;

        long long target = total / 2;

        // Check horizontal cuts
        long long sum = 0;
        for (int i = 0; i < m - 1; i++)
        {
            sum += rowSum[i];
            if (sum == target)
                return true;
        }

        // Check vertical cuts
        sum = 0;
        for (int j = 0; j < n - 1; j++)
        {
            sum += colSum[j];
            if (sum == target)
                return true;
        }

        return false;
    }
};

int main()
{
    int m, n;
    cin >> m >> n;

    vector<vector<int>> grid(m, vector<int>(n));

    // Input grid
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }

    Solution obj;
    bool result = obj.canPartitionGrid(grid);

    // Output result
    if (result)
        cout << "true\n";
    else
        cout << "false\n";

    return 0;
}