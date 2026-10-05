#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    int scoreOfParentheses(string s)
    {
        int depth = 0;
        int ans = 0;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
            {
                depth++;
            }
            else
            {
                depth--;

                // Found "()"
                if (s[i - 1] == '(')
                {
                    ans += (1 << depth);
                }
            }
        }

        return ans;
    }
};

int main()
{
    string s;

    cout << "Enter balanced parentheses string: ";
    cin >> s;

    Solution obj;

    int result = obj.scoreOfParentheses(s);

    cout << "Score: " << result << endl;

    return 0;
}