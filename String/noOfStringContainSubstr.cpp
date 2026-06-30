#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long

class Solution
{
public:
    ull numberOfSubstrings(string s)
    {
        int n = s.size();
        int cnt[3] = {0};

        int l = 0;
        ull ans = 0;

        for (int r = 0; r < n; r++)
        {
            cnt[s[r] - 'a']++;

            while (cnt[0] && cnt[1] && cnt[2])
            {
                ans += (ull)(n - r);
                cnt[s[l] - 'a']--;
                l++;
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
    cout << obj.numberOfSubstrings(s) << endl;

    return 0;
}