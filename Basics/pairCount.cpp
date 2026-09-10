#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int pairCount(int x, int y) {
        // LCM must be a multiple of GCD
        if (y % x != 0)
            return 0;

        int n = y / x;
        int ans = 0;

        // Find all factor pairs (p, q)
        for (int p = 1; p * p <= n; p++) {
            if (n % p == 0) {
                int q = n / p;

                // p and q must be coprime
                if (__gcd(p, q) == 1) {
                    if (p == q)
                        ans += 1;
                    else
                        ans += 2;
                }
            }
        }

        return ans;
    }
};

int main() {
    int x, y;

    cin >> x >> y;

    Solution obj;

    cout << obj.pairCount(x, y) << endl;

    return 0;
}