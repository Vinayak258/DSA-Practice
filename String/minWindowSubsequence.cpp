#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string minWindow(string &s1, string &s2)
    {
        int n = s1.size();
        int m = s2.size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        // Fill dp for the first character of s2
        for (int i = 0; i < n; i++)
        {
            if (s1[i] == s2[0])
            {
                dp[i][0] = i;
            }
            else if (i > 0)
            {
                dp[i][0] = dp[i - 1][0];
            }
        }

        // Fill dp table for other characters of s2
        for (int j = 1; j < m; j++)
        {
            int last = -1;
            for (int i = 0; i < n; i++)
            {
                if (last != -1 && s1[i] == s2[j])
                {
                    dp[i][j] = last;
                }
                if (dp[i][j - 1] != -1)
                {
                    last = dp[i][j - 1];
                }
            }
        }

        // Find best minimal window
        int bestLen = INT_MAX;
        int bestStart = -1;

        for (int i = 0; i < n; i++)
        {
            if (dp[i][m - 1] != -1)
            {
                int start = dp[i][m - 1];
                int len = i - start + 1;
                if (len < bestLen)
                {
                    bestLen = len;
                    bestStart = start;
                }
            }
        }

        if (bestStart == -1)
            return "";
        return s1.substr(bestStart, bestLen);
    }
};

int main()
{
    string s1, s2;

    cin >> s1 >> s2;

    Solution obj;
    cout << obj.minWindow(s1, s2) << endl;

    return 0;
}
