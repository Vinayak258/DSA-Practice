#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string minWindow(string &s, string &p)
    {
        int n = s.length();
        int m = p.length();

        vector<int> freq(256, 0);

        for (char c : p)
            freq[c]++;

        int left = 0, right = 0;
        int count = m;

        int minLen = INT_MAX;
        int start = 0;

        while (right < n)
        {

            if (freq[s[right]] > 0)
                count--;

            freq[s[right]]--;
            right++;

            while (count == 0)
            {

                if (right - left < minLen)
                {
                    minLen = right - left;
                    start = left;
                }

                freq[s[left]]++;

                if (freq[s[left]] > 0)
                    count++;

                left++;
            }
        }

        if (minLen == INT_MAX)
            return "";

        return s.substr(start, minLen);
    }
};

int main()
{
    string s, p;

    cout << "Enter string s: ";
    cin >> s;

    cout << "Enter string p: ";
    cin >> p;

    Solution obj;
    string result = obj.minWindow(s, p);

    cout << "Smallest window: " << result << endl;

    return 0;
}