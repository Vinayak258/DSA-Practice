
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkString(string s)
    {
        bool foundB = false;

        for (char ch : s)
        {
            if (ch == 'b')
            {
                foundB = true;
            }
            else if (ch == 'a' && foundB)
            {
                return false;
            }
        }

        return true;
    }
};

int main()
{
    Solution obj;

    string s;
    cout << "Enter string: ";
    cin >> s;

    if (obj.checkString(s))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }

    return 0;
}
