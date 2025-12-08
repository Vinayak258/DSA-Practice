#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    static const long long MOD = 1000000007;

    long long modPow(long long base, long long exp)
    {
        long long result = 1;
        base %= MOD;
        while (exp > 0)
        {
            if (exp & 1)
                result = (result * base) % MOD;
            base = (base * base) % MOD;
            exp >>= 1;
        }
        return result;
    }

    int countGoodNumbers(long long n)
    {
        long long even = (n + 1) / 2; // number of even positions
        long long odd = n / 2;        // number of odd positions
        long long part1 = modPow(5, even);
        long long part2 = modPow(4, odd);
        return (part1 * part2) % MOD;
    }
};

int main()
{
    long long n;
    cin >> n;

    Solution sol;
    cout << sol.countGoodNumbers(n) << endl;

    return 0;
}
