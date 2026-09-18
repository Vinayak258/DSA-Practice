#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> maxNumOfSubstrings(string s)
    {
        int n = s.size();

        // first[i] = first occurrence of character i
        // last[i]  = last occurrence of character i
        vector<int> first(26, n);
        vector<int> last(26, -1);

        // Find first and last occurrence
        for (int i = 0; i < n; i++)
        {
            int c = s[i] - 'a';

            first[c] = min(first[c], i);
            last[c] = i;
        }

        vector<pair<int, int>> intervals;

        // Construct the smallest valid interval
        // for every character
        for (int c = 0; c < 26; c++)
        {

            // Character does not exist
            if (last[c] == -1)
                continue;

            int l = first[c];
            int r = last[c];

            bool valid = true;

            for (int i = l; i <= r; i++)
            {
                int x = s[i] - 'a';

                // Character occurs before l.
                // Therefore this interval cannot be valid.
                if (first[x] < l)
                {
                    valid = false;
                    break;
                }

                // We need to include all occurrences
                // of this character.
                r = max(r, last[x]);
            }

            if (valid)
            {
                intervals.push_back({l, r});
            }
        }

        // Sort by ending position
        sort(intervals.begin(), intervals.end(),
             [](const pair<int, int> &a,
                const pair<int, int> &b)
             {
                 return a.second < b.second;
             });

        vector<string> ans;

        int prevEnd = -1;

        // Greedily choose non-overlapping intervals
        for (auto [l, r] : intervals)
        {

            if (l > prevEnd)
            {
                ans.push_back(s.substr(l, r - l + 1));
                prevEnd = r;
            }
        }

        return ans;
    }
};

int main()
{

    Solution sol;

    string s;

    cout << "Enter string: ";
    cin >> s;

    vector<string> ans = sol.maxNumOfSubstrings(s);

    cout << "Maximum number of non-overlapping substrings:\n";

    for (string str : ans)
    {
        cout << str << " ";
    }

    cout << "\n";

    return 0;
}