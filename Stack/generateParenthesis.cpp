#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    void backtrack(int n, int open, int close, string &curr,
                   vector<string> &ans)
    {
        if (curr.size() == 2 * n)
        {
            ans.push_back(curr);
            return;
        }

        // Add opening bracket
        if (open < n)
        {
            curr.push_back('(');
            backtrack(n, open + 1, close, curr, ans);
            curr.pop_back();
        }

        // Add closing bracket only if valid
        if (close < open)
        {
            curr.push_back(')');
            backtrack(n, open, close + 1, curr, ans);
            curr.pop_back();
        }
    }

    vector<string> generateParenthesis(int n)
    {
        vector<string> ans;
        string curr;
        backtrack(n, 0, 0, curr, ans);
        return ans;
    }
};

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;

    Solution sol;
    vector<string> result = sol.generateParenthesis(n);

    cout << "Valid combinations:\n";
    for (const string &s : result)
    {
        cout << s << '\n';
    }

    return 0;
}