#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        string ans = "";

        int n = strs.size();
        if (n == 0)
            return ans;

        for (int i = 0; i < strs[0].size(); i++)
        {
            char ch = strs[0][i];
            bool match = true;

            for (int j = 1; j < n; j++)
            {
                // Fix: check if index i is within bounds
                if (i >= strs[j].size() || ch != strs[j][i])
                {
                    match = false;
                    break;
                }
            }

            if (!match)
                break;
            ans.push_back(ch);
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<string> strs;

    cout << "Enter number of strings: ";
    int n;
    cin >> n;

    cout << "Enter the strings:\n";
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        strs.push_back(s);
    }

    string result = sol.longestCommonPrefix(strs);
    cout << "Longest Common Prefix: " << result << endl;

    return 0;
}
