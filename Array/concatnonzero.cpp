#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    static const int MOD = 1000000007;

    long long modPow(long long a, long long b)
    {
        long long res = 1;
        while (b)
        {
            if (b & 1)
                res = (res * a) % MOD;
            a = (a * a) % MOD;
            b >>= 1;
        }
        return res;
    }

    vector<int> sumAndMultiply(string s, vector<vector<int>> &queries)
    {
        int n = s.size();

        vector<int> preCnt(n + 1, 0), preSum(n + 1, 0);
        vector<int> pos(n + 1, 0);

        vector<long long> pref;
        pref.push_back(0);

        for (int i = 0; i < n; i++)
        {
            preCnt[i + 1] = preCnt[i];
            preSum[i + 1] = preSum[i];
            pos[i + 1] = pref.size() - 1;

            if (s[i] != '0')
            {
                int d = s[i] - '0';
                preCnt[i + 1]++;
                preSum[i + 1] += d;
                pref.push_back((pref.back() * 10 + d) % MOD);
                pos[i + 1] = pref.size() - 1;
            }
        }

        int m = pref.size() - 1;

        vector<long long> power(m + 1);
        power[0] = 1;
        for (int i = 1; i <= m; i++)
            power[i] = (power[i - 1] * 10) % MOD;

        vector<int> ans;

        for (auto &q : queries)
        {
            int l = q[0];
            int r = q[1];

            int sum = preSum[r + 1] - preSum[l];

            int left = pos[l];
            int right = pos[r + 1];

            int len = right - left;

            long long x = 0;
            if (len > 0)
            {
                x = (pref[right] - pref[left] * power[len]) % MOD;
                if (x < 0)
                    x += MOD;
            }

            ans.push_back((x * sum) % MOD);
        }

        return ans;
    }
};

int main()
{
    Solution obj;

    string s;
    cin >> s;

    int q;
    cin >> q;

    vector<vector<int>> queries(q, vector<int>(2));

    for (int i = 0; i < q; i++)
    {
        cin >> queries[i][0] >> queries[i][1];
    }

    vector<int> ans = obj.sumAndMultiply(s, queries);

    for (int x : ans)
        cout << x << " ";

    cout << endl;

    return 0;
}