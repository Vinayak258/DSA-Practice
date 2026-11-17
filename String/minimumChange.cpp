
class Solution
{
public:
    int minimumChanges(string s, int k)
    {
        int n = s.size();
        const int INF = 1e9;

        // cost[i][j] = minimum changes to make s[i...j]
        // a semi-palindrome
        vector<vector<int>> cost(n, vector<int>(n, INF));

        // Precompute semi-palindrome costs
        for (int l = 0; l < n; l++)
        {
            for (int r = l + 1; r < n; r++)
            {
                int len = r - l + 1;

                // Try every proper divisor
                for (int d = 1; d < len; d++)
                {
                    if (len % d != 0)
                        continue;

                    int changes = 0;

                    // Check each group
                    for (int a = 0; a < d; a++)
                    {
                        int cnt = len / d;

                        // Compare symmetric characters
                        for (int t = 0; t < cnt / 2; t++)
                        {
                            int x = l + a + t * d;
                            int y = l + a + (cnt - 1 - t) * d;

                            if (s[x] != s[y])
                                changes++;
                        }
                    }

                    cost[l][r] = min(cost[l][r], changes);
                }
            }
        }

        // dp[i][j] = minimum changes to partition
        // first i characters into exactly j parts
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, INF));

        dp[0][0] = 0;

        for (int parts = 1; parts <= k; parts++)
        {
            for (int i = 2 * parts; i <= n; i++)
            {

                // Last substring is s[start ... i-1]
                for (int start = 2 * (parts - 1);
                     start <= i - 2; start++)
                {

                    if (dp[start][parts - 1] == INF)
                        continue;

                    dp[i][parts] = min(
                        dp[i][parts],
                        dp[start][parts - 1] + cost[start][i - 1]);
                }
            }
        }

        return dp[n][k];
    }
};
