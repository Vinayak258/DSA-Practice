#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumCost(int x, int s, int m, int l, int cs, int cm, int cl)
    {
        const int INF = 1e9;

        vector<int> dp(x + 1, INF);
        dp[0] = 0;

        for (int area = 0; area <= x; area++)
        {
            if (dp[area] == INF)
                continue;

            // Buy Small pizza
            int newArea = min(x, area + s);
            dp[newArea] = min(dp[newArea], dp[area] + cs);

            // Buy Medium pizza
            newArea = min(x, area + m);
            dp[newArea] = min(dp[newArea], dp[area] + cm);

            // Buy Large pizza
            newArea = min(x, area + l);
            dp[newArea] = min(dp[newArea], dp[area] + cl);
        }

        return dp[x];
    }
};

int main()
{
    int x, s, m, l;
    int cs, cm, cl;

    // Input:
    // x  = required area
    // s  = small pizza area
    // m  = medium pizza area
    // l  = large pizza area
    // cs = small pizza cost
    // cm = medium pizza cost
    // cl = large pizza cost

    cin >> x >> s >> m >> l >> cs >> cm >> cl;

    Solution obj;

    int answer = obj.minimumCost(x, s, m, l, cs, cm, cl);

    cout << answer << endl;

    return 0;
}