#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findPeakGrid(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();

        int left = 0, right = m - 1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            // Find max element in mid column
            int maxRow = 0;
            for (int i = 0; i < n; i++)
            {
                if (mat[i][mid] > mat[maxRow][mid])
                {
                    maxRow = i;
                }
            }

            int leftVal = (mid - 1 >= 0) ? mat[maxRow][mid - 1] : INT_MIN;
            int rightVal = (mid + 1 < m) ? mat[maxRow][mid + 1] : INT_MIN;

            // Check peak condition
            if (mat[maxRow][mid] >= leftVal && mat[maxRow][mid] >= rightVal)
            {
                return {maxRow, mid};
            }
            else if (leftVal > mat[maxRow][mid])
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }

        return {-1, -1};
    }
};

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> mat(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mat[i][j];
        }
    }

    Solution obj;
    vector<int> ans = obj.findPeakGrid(mat);

    int r = ans[0];
    int c = ans[1];

    bool isPeak = true;
    int val = mat[r][c];

    // Check all 4 directions
    if (r - 1 >= 0 && mat[r - 1][c] > val)
        isPeak = false;
    if (r + 1 < n && mat[r + 1][c] > val)
        isPeak = false;
    if (c - 1 >= 0 && mat[r][c - 1] > val)
        isPeak = false;
    if (c + 1 < m && mat[r][c + 1] > val)
        isPeak = false;

    cout << (isPeak ? "true" : "false") << endl;

    return 0;
}
