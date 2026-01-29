#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string firstNonRepeating(string &s)
    {
        vector<int> freq(26, 0);
        queue<char> q;
        string ans = "";

        for (char ch : s)
        {
            freq[ch - 'a']++;
            q.push(ch);

            // Remove repeating characters
            while (!q.empty() && freq[q.front() - 'a'] > 1)
            {
                q.pop();
            }

            if (q.empty())
                ans.push_back('#');
            else
                ans.push_back(q.front());
        }

        return ans;
    }
};

int main()
{
    string s;
    cin >> s;

    Solution obj;
    cout << obj.firstNonRepeating(s);

    return 0;
}
