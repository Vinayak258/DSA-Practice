#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool rotateString(string s, string goal)
    {
        // Strings must be same length
        if (s.length() != goal.length())
            return false;

        // Check if goal is a substring of s+s
        string doubled = s + s;
        return doubled.find(goal) != string::npos;
    }
};

int main()
{
    Solution sol;
    string s, goal;

    cout << "Enter string s: ";
    cin >> s;

    cout << "Enter goal string: ";
    cin >> goal;

    bool result = sol.rotateString(s, goal);

    if (result)
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}
