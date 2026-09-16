#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSets(int n, int k) {
        const int MOD = 1e9 + 7;

        vector<vector<long long>> dp(k + 1,
                                    vector<long long>(n, 0));

        // 0 segments can always be formed in 1 way
        for (int i = 0; i < n; i++) {
            dp[0][i] = 1;
        }

        for (int segments = 1; segments <= k; segments++) {
            long long sum = 0;

            for (int i = 1; i < n; i++) {

                // Ways to start a new segment
                sum = (sum + dp[segments - 1][i - 1]) % MOD;

                // Either:
                // 1. Don't end a segment at i
                // 2. End a segment at i
                dp[segments][i] =
                    (dp[segments][i - 1] + sum) % MOD;
            }
        }

        return dp[k][n - 1];
    }
};

int main() {
    Solution obj;

    int n, k;

    cout << "Enter n and k: ";
    cin >> n >> k;

    cout << "Number of ways: "
         << obj.numberOfSets(n, k) << endl;

    return 0;
}