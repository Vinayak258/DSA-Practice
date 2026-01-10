#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long atMostK(const string &s, int k)
    {
        if (k == 0)
            return 0;

        vector<int> freq(26, 0);
        long long count = 0;
        int left = 0, distinct = 0;

        for (int right = 0; right < (int)s.size(); right++)
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

            count += (right - left + 1);
        }
        return count;
    }

    int countSubstr(string &s, int k)
    {
        return atMostK(s, k) - atMostK(s, k - 1);
    }
};

int main()
{
    string s;
    int k;
    cin >> s >> k;

    Solution obj;
    cout << obj.countSubstr(s, k) << endl;

    return 0;
}
