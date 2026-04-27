#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int smallestSubstring(string s)
    {
        int n = s.size();
        vector<int> count(3, 0); // counts for '0', '1', '2'

        int left = 0;
        int minLen = INT_MAX;

        for (int right = 0; right < n; right++)
        {
            count[s[right] - '0']++;

            // Check if current window contains all '0', '1', '2'
            while (count[0] > 0 && count[1] > 0 && count[2] > 0)
            {
                minLen = min(minLen, right - left + 1);

                // Shrink window from left
                count[s[left] - '0']--;
                left++;
            }
        }

        return (minLen == INT_MAX) ? -1 : minLen;
    }
};

int main()
{
    Solution obj;

    string s;
    cin >> s;

    int result = obj.smallestSubstring(s);
    cout << result << endl;

    return 0;
}