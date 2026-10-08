#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    string removeOuterParentheses(string s)
    {
        string ans;
        int depth = 0;

        for (char c : s)
        {
            if (c == '(')
            {
                // Don't add the outermost '('
                if (depth > 0)
                {
                    ans += c;
                }
                depth++;
            }
            else
            {
                depth--;

                // Don't add the outermost ')'
                if (depth > 0)
                {
                    ans += c;
                }
            }
        }

        return ans;
    }
};

int main()
{
    Solution obj;

    string s;
    cout << "Enter parentheses string: ";
    cin >> s;

    string result = obj.removeOuterParentheses(s);

    cout << "Result: " << result << endl;

    return 0;
}