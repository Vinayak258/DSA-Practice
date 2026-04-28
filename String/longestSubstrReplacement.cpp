#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestSubstr(string &s, int k)
    {
        vector<int> freq(26, 0);
        int left = 0, maxFreq = 0, ans = 0;

        for (int right = 0; right < s.size(); right++)
        {
            freq[s[right] - 'A']++;
            maxFreq = max(maxFreq, freq[s[right] - 'A']);

            // If window is invalid, shrink it
            while ((right - left + 1) - maxFreq > k)
            {
                freq[s[left] - 'A']--;
                left++;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};

int main()
{
    string s;
    int k;

    // Input
    cin >> s >> k;

    Solution obj;
    cout << obj.longestSubstr(s, k) << endl;

    return 0;
}