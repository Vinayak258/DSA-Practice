#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int palindromicStrings(int n, int k)
    {
        const long long MOD = 1000000007;

        long long ans = 0;

        // perm = P(k, half)
        // Initially P(k, 0) = 1
        long long perm = 1;

        for (int half = 0; 2 * half <= n; half++)
        {

            // Odd length = 2 * half + 1
            if (2 * half + 1 <= n)
            {
                long long odd = perm * (k - half) % MOD;
                ans = (ans + odd) % MOD;
            }

            // Even length = 2 * half
            // Skip length 0
            if (half > 0 && 2 * half <= n)
            {
                ans = (ans + perm) % MOD;
            }

            // Calculate P(k, half + 1)
            if (half < k)
            {
                perm = perm * (k - half) % MOD;
            }
        }

        return ans;
    }
};

int main()
{
    int n, k;

    cin >> n >> k;

    Solution obj;

    cout << obj.palindromicStrings(n, k) << endl;

    return 0;
}