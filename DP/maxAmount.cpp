#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumAmount(vector<vector<int>> &coins)
    {
        int m = coins.size(), n = coins[0].size();
        const int NEG = -1e9;

        // dp[i][j][used] = max money at cell (i,j)
        // after using 'used' neutralizations
        vector<vector<vector<int>>> dp(
            m, vector<vector<int>>(n, vector<int>(3, NEG)));

        // start cell
        dp[0][0][0] = coins[0][0];
        if (coins[0][0] < 0)
        {
            dp[0][0][1] = 0; // neutralize start robber
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 && j == 0)
                    continue;

                for (int used = 0; used <= 2; used++)
                {
                    int best = NEG;

                    // from top
                    if (i > 0)
                        best = max(best, dp[i - 1][j][used]);

                    // from left
                    if (j > 0)
                        best = max(best, dp[i][j - 1][used]);

                    if (best == NEG)
                        continue;

                    // option 1: take current cell normally
                    dp[i][j][used] = max(dp[i][j][used],
                                         best + coins[i][j]);

                    // option 2: neutralize robber if current cell is negative
                    if (coins[i][j] < 0 && used < 2)
                    {
                        dp[i][j][used + 1] =
                            max(dp[i][j][used + 1], best);
                    }
                }
            }
        }

        return max({dp[m - 1][n - 1][0],
                    dp[m - 1][n - 1][1],
                    dp[m - 1][n - 1][2]});
    }
};

int main()
{
    vector<vector<int>> coins = {
        {-4, 5, 7, 16},
        {-2, -19, 5, -20},
        {-7, -19, 16, -1},
        {-20, -1, 16, 14}};

    Solution obj;
    cout << "Maximum amount = " << obj.maximumAmount(coins) << endl;

    return 0;
}