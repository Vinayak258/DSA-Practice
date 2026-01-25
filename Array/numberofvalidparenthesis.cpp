#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findWays(int n)
    {
        if (n % 2 != 0)
            return 0;

        int k = n / 2;
        vector<long long> dp(k + 1, 0);

        dp[0] = 1;
        dp[1] = 1;

        for (int i = 2; i <= k; i++)
        {
            for (int j = 0; j < i; j++)
            {
                dp[i] += dp[j] * dp[i - j - 1];
            }
        }

        return dp[k];
    }
};

int main()
{
    int n;
    cin >> n;

    Solution obj;
    cout << obj.findWays(n);

    return 0;
}
