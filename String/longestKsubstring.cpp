#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestKSubstr(string &s, int k)
    {
        vector<int> freq(26, 0);
        int left = 0, distinct = 0, maxLen = -1;

        for (int right = 0; right < s.size(); right++)
        {
            if (freq[s[right] - 'a'] == 0)
                distinct++;

            freq[s[right] - 'a']++;

            while (distinct > k)
            {
                freq[s[left] - 'a']--;
                if (freq[s[left] - 'a'] == 0)
                    distinct--;
                left++;
            }

            if (distinct == k)
                maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};

int main()
{
    string s;
    int k;

    cout << "Enter string: ";
    cin >> s;

    cout << "Enter k: ";
    cin >> k;

    Solution obj;
    int result = obj.longestKSubstr(s, k);

    cout << "Longest substring length with exactly " << k
         << " distinct characters: " << result << endl;

    return 0;
}