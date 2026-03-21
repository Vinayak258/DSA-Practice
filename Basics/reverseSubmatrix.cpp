#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>> &grid, int x, int y, int k)
    {
        // Flip the k x k submatrix vertically
        for (int i = 0; i < k / 2; i++)
        {
            for (int j = 0; j < k; j++)
            {
                swap(grid[x + i][y + j], grid[x + k - 1 - i][y + j]);
            }
        }
        return grid;
    }
};

int main()
{
    // Example input
    vector<vector<int>> grid = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}};

    int x = 1, y = 0, k = 3;

    Solution sol;
    vector<vector<int>> result = sol.reverseSubmatrix(grid, x, y, k);

    // Print result
    cout << "Updated Matrix:\n";
    for (auto &row : result)
    {
        for (auto &val : row)
        {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}