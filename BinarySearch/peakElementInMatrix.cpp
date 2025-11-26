#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findPeakGrid(vector<vector<int>> &mat)
    {
        int m = mat.size();
        int n = mat[0].size();

        int left = 0, right = n - 1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            int maxRow = 0;

            // find maximum element row in this column
            for (int r = 1; r < m; r++)
            {
                if (mat[r][mid] > mat[maxRow][mid])
                {
                    maxRow = r;
                }
            }

            int current = mat[maxRow][mid];
            int leftVal = (mid - 1 >= 0) ? mat[maxRow][mid - 1] : -1;
            int rightVal = (mid + 1 < n) ? mat[maxRow][mid + 1] : -1;

            if (current > leftVal && current > rightVal)
            {
                return {maxRow, mid}; // peak found
            }

            if (leftVal > current)
            {
                right = mid - 1; // search left
            }
            else
            {
                left = mid + 1; // search right
            }
        }
        return {-1, -1}; // should never happen
    }
};

int main()
{
    vector<vector<int>> mat = {
        {10, 20, 15},
        {21, 30, 14},
        {7, 16, 32}};

    Solution sol;
    vector<int> peak = sol.findPeakGrid(mat);

    cout << "Peak element found at index: [" << peak[0] << ", " << peak[1] << "]" << endl;
    cout << "Value = " << mat[peak[0]][peak[1]] << endl;

    return 0;
}
