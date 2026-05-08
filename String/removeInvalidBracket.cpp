#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to check whether a string is valid
    bool isValid(string &s)
    {
        int balance = 0;

        for (char c : s)
        {

            if (c == '(')
            {
                balance++;
            }

            else if (c == ')')
            {

                balance--;

                // More closing brackets than opening
                if (balance < 0)
                    return false;
            }
        }

        // Valid only if all brackets matched
        return balance == 0;
    }

    vector<string> validParenthesis(string &s)
    {

        vector<string> ans;

        queue<string> q;
        unordered_set<string> visited;

        q.push(s);
        visited.insert(s);

        bool found = false;

        while (!q.empty())
        {

            string curr = q.front();
            q.pop();

            // Check if current string is valid
            if (isValid(curr))
            {
                ans.push_back(curr);
                found = true;
            }

            // If valid string found at this level,
            // don't go deeper
            if (found)
                continue;

            // Generate all possible states
            // by removing one parenthesis
            for (int i = 0; i < curr.size(); i++)
            {

                // Ignore non-parenthesis characters
                if (curr[i] != '(' && curr[i] != ')')
                    continue;

                string next =
                    curr.substr(0, i) +
                    curr.substr(i + 1);

                // Avoid duplicate processing
                if (!visited.count(next))
                {
                    visited.insert(next);
                    q.push(next);
                }
            }
        }

        // Remove duplicates and sort lexicographically
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());

        return ans;
    }
};

int main()
{

    string s;
    cin >> s;

    Solution obj;

    vector<string> result = obj.validParenthesis(s);

    for (string str : result)
    {
        cout << str << endl;
    }

    return 0;
}