#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int distinctSubseqII(string s)
    {
        const int MOD = 1e9 + 7;

        long long total = 0;
        long long end[26] = {0};

        for (char c : s)
        {
            int index = c - 'a';

            // Number of new subsequences created by adding c
            long long newSubsequences = (total + 1) % MOD;

            // Remove the subsequences that were already
            // ending with the same character
            total = (total + newSubsequences - end[index] + MOD) % MOD;

            // All subsequences ending with c are now
            // exactly newSubsequences
            end[index] = newSubsequences;
        }

        return total;
    }
};

int main()
{
    Solution obj;

    string s;
    cin >> s;

    cout << obj.distinctSubseqII(s) << endl;

    return 0;
}