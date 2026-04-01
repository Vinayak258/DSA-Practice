#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string findTheString(vector<vector<int>> &lcp)
    {
        int n = lcp.size();

        // Step 1: Validate diagonal
        for (int i = 0; i < n; i++)
        {
            if (lcp[i][i] != n - i)
                return "";
        }

        // Step 2: DSU setup
        vector<int> parent(n);
        for (int i = 0; i < n; i++)
            parent[i] = i;

        function<int(int)> find = [&](int x)
        {
            if (parent[x] == x)
                return x;
            return parent[x] = find(parent[x]);
        };

        auto unite = [&](int a, int b)
        {
            a = find(a);
            b = find(b);
            if (a != b)
                parent[b] = a;
        };

        // Step 3: Merge indices with lcp > 0
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (lcp[i][j] > 0)
                {
                    unite(i, j);
                }
            }
        }

        // Step 4: Assign characters
        vector<char> res(n);
        unordered_map<int, char> mp;
        char ch = 'a';

        for (int i = 0; i < n; i++)
        {
            int p = find(i);
            if (!mp.count(p))
            {
                if (ch > 'z')
                    return "";
                mp[p] = ch++;
            }
            res[i] = mp[p];
        }

        // Step 5: Validate full LCP matrix
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                int expected = 0;

                if (res[i] == res[j])
                {
                    if (i + 1 < n && j + 1 < n)
                        expected = 1 + lcp[i + 1][j + 1];
                    else
                        expected = 1;
                }

                if (lcp[i][j] != expected)
                    return "";
            }
        }

        return string(res.begin(), res.end());
    }
};

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> lcp(n, vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> lcp[i][j];
        }
    }

    Solution obj;
    string result = obj.findTheString(lcp);

    if (result.empty())
    {
        cout << "\"\"" << endl; // matches LeetCode style
    }
    else
    {
        cout << result << endl;
    }

    return 0;
} 