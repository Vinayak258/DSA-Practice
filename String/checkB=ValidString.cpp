
#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    bool checkValidString(string s)
    {
        int low = 0, high = 0;

        for (char c : s)
        {
            if (c == '(')
            {
                low++;
                high++;
            }
            else if (c == ')')
            {
                low--;
                high--;
            }
            else
            { // '*'
                low--;
                high++;
            }

            if (high < 0)
            {
                return false;
            }

            if (low < 0)
            {
                low = 0;
            }
        }

        return low == 0;
    }
};

int main()
{
    Solution sol;
    string s;

    cout << "Enter a string containing (, ) and *: ";
    cin >> s;

    if (sol.checkValidString(s))
    {
        cout << "Valid Parenthesis String" << endl;
    }
    else
    {
        cout << "Invalid Parenthesis String" << endl;
    }

    return 0;
}
