
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minChanges(string s)
    {
        int ans = 0;

        for (int i = 0; i < s.size(); i += 2)
        {
            if (s[i] != s[i + 1])
            {
                ans++;
            }
        }

        return ans;
    }
};

int main()
{
    string s;
    cin >> s;

    Solution obj;
    cout << obj.minChanges(s) << endl;

    return 0;
}
