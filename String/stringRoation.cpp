#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool areRotations(string &s1, string &s2)
    {
        if (s1.length() != s2.length())
        {
            return false;
        }

        string temp = s1 + s1;
        return temp.find(s2) != string::npos;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s1, s2;
    cin >> s1 >> s2;

    Solution obj;
    cout << (obj.areRotations(s1, s2) ? "true" : "false");

    return 0;
}
