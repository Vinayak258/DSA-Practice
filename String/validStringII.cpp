#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> ans;

    void solve(string &s, int index,
               int leftRem, int rightRem,
               int open, string curr)
    {

        // Reached the end
        if (index == s.size())
        {

            // Valid result
            if (leftRem == 0 &&
                rightRem == 0 &&
                open == 0)
            {

                ans.push_back(curr);
            }

            return;
        }

        char ch = s[index];

        // -------------------------
        // Case 1: '('
        // -------------------------
        if (ch == '(')
        {

            // Option 1: Remove '('
            if (leftRem > 0)
            {
                solve(s,
                      index + 1,
                      leftRem - 1,
                      rightRem,
                      open,
                      curr);
            }

            // Option 2: Keep '('
            solve(s,
                  index + 1,
                  leftRem,
                  rightRem,
                  open + 1,
                  curr + ch);
        }

        // -------------------------
        // Case 2: ')'
        // -------------------------
        else if (ch == ')')
        {

            // Option 1: Remove ')'
            if (rightRem > 0)
            {
                solve(s,
                      index + 1,
                      leftRem,
                      rightRem - 1,
                      open,
                      curr);
            }

            // Option 2: Keep ')'
            // Only possible if there is
            // an unmatched '('
            if (open > 0)
            {
                solve(s,
                      index + 1,
                      leftRem,
                      rightRem,
                      open - 1,
                      curr + ch);
            }
        }

        // -------------------------
        // Case 3: Letter
        // -------------------------
        else
        {

            solve(s,
                  index + 1,
                  leftRem,
                  rightRem,
                  open,
                  curr + ch);
        }
    }

    vector<string> removeInvalidParentheses(string s)
    {

        int leftRem = 0;
        int rightRem = 0;

        // Find minimum removals required
        for (char ch : s)
        {

            if (ch == '(')
            {
                leftRem++;
            }

            else if (ch == ')')
            {

                if (leftRem > 0)
                {
                    leftRem--;
                }
                else
                {
                    rightRem++;
                }
            }
        }

        // Start backtracking
        solve(s, 0,
              leftRem,
              rightRem,
              0,
              "");

        // Remove duplicate answers
        sort(ans.begin(), ans.end());

        ans.erase(
            unique(ans.begin(), ans.end()),
            ans.end());

        return ans;
    }
};

int main()
{

    Solution obj;

    string s;

    cout << "Enter string: ";
    cin >> s;

    vector<string> result =
        obj.removeInvalidParentheses(s);

    cout << "\nValid strings with minimum removals:\n";

    for (string str : result)
    {
        cout << str << endl;
    }

    return 0;
}