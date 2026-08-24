#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    const long long MOD = 1000000007;

    long long power(long long base, long long exp)
    {
        long long result = 1;

        while (exp > 0)
        {
            if (exp & 1)
                result = (result * base) % MOD;

            base = (base * base) % MOD;
            exp >>= 1;
        }

        return result;
    }

    int prefixStrings(int n)
    {
        vector<long long> fact(2 * n + 1);

        fact[0] = 1;

        for (int i = 1; i <= 2 * n; i++)
        {
            fact[i] = (fact[i - 1] * i) % MOD;
        }

        // C(2n, n) = (2n)! / (n! * n!)
        long long numerator = fact[2 * n];

        long long denominator =
            (fact[n] * fact[n]) % MOD;

        long long inverseDenominator =
            power(denominator, MOD - 2);

        long long combination =
            (numerator * inverseDenominator) % MOD;

        // Catalan number
        // Cn = C(2n, n) / (n + 1)
        long long inverse =
            power(n + 1, MOD - 2);

        return (combination * inverse) % MOD;
    }
};

int main()
{
    int n;

    cin >> n;

    Solution obj;

    cout << obj.prefixStrings(n) << endl;

    return 0;
}