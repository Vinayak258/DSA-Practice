#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canBeEqual(string s1, string s2)
    {
        // Check even indices (0,2)
        bool evenMatch =
            (s1[0] == s2[0] && s1[2] == s2[2]) ||
            (s1[0] == s2[2] && s1[2] == s2[0]);

        // Check odd indices (1,3)
        bool oddMatch =
            (s1[1] == s2[1] && s1[3] == s2[3]) ||
            (s1[1] == s2[3] && s1[3] == s2[1]);

        return evenMatch && oddMatch;
    }
};

int main()
{
    Solution obj;

    string s1, s2;

    cout << "Enter string s1: ";
    cin >> s1;

    cout << "Enter string s2: ";
    cin >> s2;

    if (obj.canBeEqual(s1, s2))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }

    return 0;
}