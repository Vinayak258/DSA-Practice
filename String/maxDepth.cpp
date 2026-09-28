#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxDepth(string s)
    {
        int depth = 0;
        int ans = 0;

        for (char ch : s)
        {
            if (ch == '(')
            {
                depth++;
                ans = max(ans, depth);
            }
            else if (ch == ')')
            {
                depth--;
            }
        }

        return ans;
    }
};

int main()
{
    Solution sol;

    string s;
    getline(cin, s);

    cout << sol.maxDepth(s) << endl;

    return 0;
}