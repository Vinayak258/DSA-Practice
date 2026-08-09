#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int zigzagSequence(vector<vector<int>> &mat)
    {
        int n = mat.size();

        // dp[j] = maximum sum ending at column j
        vector<int> dp(n);

        // First row
        for (int j = 0; j < n; j++)
        {
            dp[j] = mat[0][j];
        }

        // Process remaining rows
        for (int i = 1; i < n; i++)
        {

            // Find largest and second largest values
            // in the previous row
            int max1 = -1;
            int max2 = -1;
            int max1Index = -1;

            for (int j = 0; j < n; j++)
            {
                if (dp[j] > max1)
                {
                    max2 = max1;
                    max1 = dp[j];
                    max1Index = j;
                }
                else if (dp[j] > max2)
                {
                    max2 = dp[j];
                }
            }

            vector<int> newDp(n);

            for (int j = 0; j < n; j++)
            {

                // Cannot choose the same column
                // as the previous element
                if (j != max1Index)
                {
                    newDp[j] = mat[i][j] + max1;
                }
                else
                {
                    newDp[j] = mat[i][j] + max2;
                }
            }

            dp = newDp;
        }

        // Maximum sum from the last row
        return *max_element(dp.begin(), dp.end());
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

    Solution obj;

    cout << obj.zigzagSequence(mat) << endl;

    return 0;
}