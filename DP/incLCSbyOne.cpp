#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int waysToIncreaseLCSBy1(string &s1, string &s2)
    {
        int n = s1.size();
        int m = s2.size();

        vector<vector<int>> dp1(n + 1, vector<int>(m + 1, 0));

        // Prefix LCS
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (s1[i - 1] == s2[j - 1])
                {
                    dp1[i][j] = dp1[i - 1][j - 1] + 1;
                }
                else
                {
                    dp1[i][j] = max(dp1[i - 1][j], dp1[i][j - 1]);
                }
            }
        }

        int lcs = dp1[n][m];

        vector<vector<int>> dp2(n + 1, vector<int>(m + 1, 0));

        // Suffix LCS
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                if (s1[i] == s2[j])
                {
                    dp2[i][j] = dp2[i + 1][j + 1] + 1;
                }
                else
                {
                    dp2[i][j] = max(dp2[i + 1][j], dp2[i][j + 1]);
                }
            }
        }

        int answer = 0;

        // Try inserting at every position in s1
        for (int pos = 0; pos <= n; pos++)
        {
            vector<int> used(26, 0);

            for (int j = 0; j < m; j++)
            {
                int ch = s2[j] - 'a';

                if (used[ch])
                    continue;

                if (dp1[pos][j] + dp2[pos][j + 1] == lcs)
                {
                    answer++;
                    used[ch] = 1;
                }
            }
        }

        return answer;
    }
};

int main()
{
    string s1, s2;

    cin >> s1 >> s2;

    Solution obj;

    cout << obj.waysToIncreaseLCSBy1(s1, s2) << endl;

    return 0;
}