#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int kthSmallest(vector<vector<int>> &mat, int k)
    {
        int n = mat.size();
        int low = mat[0][0];
        int high = mat[n - 1][n - 1];

        while (low < high)
        {
            int mid = low + (high - low) / 2;
            int count = 0;

            int row = 0, col = n - 1;

            // Count elements <= mid
            while (row < n && col >= 0)
            {
                if (mat[row][col] <= mid)
                {
                    count += (col + 1);
                    row++;
                }
                else
                {
                    col--;
                }
            }

            if (count < k)
                low = mid + 1;
            else
                high = mid;
        }

        return low;
    }
};

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> mat(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> mat[i][j];
        }
    }

    int k;
    cin >> k;

    Solution obj;
    cout << obj.kthSmallest(mat, k);

    return 0;
}
