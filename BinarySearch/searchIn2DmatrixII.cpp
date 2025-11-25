#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        int r = 0;
        int c = n - 1;

        while (r < m && c >= 0)
        {
            if (matrix[r][c] == target)
            {
                return true;
            }
            else if (matrix[r][c] > target)
            {
                c--; // move left
            }
            else
            {
                r++; // move down
            }
        }
        return false;
    }
};

int main()
{
    // Example input
    vector<vector<int>> matrix = {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}};

    int target;
    cout << "Enter target: ";
    cin >> target;

    Solution sol;
    bool result = sol.searchMatrix(matrix, target);

    cout << (result ? "true" : "false") << endl;

    return 0;
}
