#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        if (s.length() != t.length())
            return false;

        unordered_map<char, char> st, ts;

        for (int i = 0; i < s.length(); ++i)
        {
            if ((st.count(s[i]) && st[s[i]] != t[i]) ||
                (ts.count(t[i]) && ts[t[i]] != s[i]))
            {
                return false;
            }
            st[s[i]] = t[i];
            ts[t[i]] = s[i];
        }
        return true;
    }
};

int main()
{
    Solution sol;

    string s, t;
    cout << "Enter first string: ";
    cin >> s;
    cout << "Enter second string: ";
    cin >> t;

    if (sol.isIsomorphic(s, t))
        cout << "Yes, the strings are isomorphic." << endl;
    else
        cout << "No, the strings are not isomorphic." << endl;

    return 0;
}
