#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    string removeOuterParentheses(string s)
    {
        string result;
        int depth = 0;
        for (char c : s)
        {
            if (c == '(')
            {
                if (depth > 0)
                    result += c; // Not the outermost '('
                depth++;
            }
            else
            { // c == ')'
                depth--;
                if (depth > 0)
                    result += c; // Not the outermost ')'
            }
        }
        return result;
    }
};

int main()
{
    Solution sol;
    string s;

    cout << "Enter parentheses string: ";
    cin >> s;

    string result = sol.removeOuterParentheses(s);
    cout << "After removing outermost parentheses: " << result << endl;
    return 0;
}
