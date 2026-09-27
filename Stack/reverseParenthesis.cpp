#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string reverseParentheses(string s)
    {

        stack<string> st;
        string curr = "";

        for (char c : s)
        {

            if (c == '(')
            {
                st.push(curr);
                curr = "";
            }
            else if (c == ')')
            {
                reverse(curr.begin(), curr.end());

                curr = st.top() + curr;
                st.pop();
            }
            else
            {
                curr += c;
            }
        }

        return curr;
    }
};

int main()
{

    Solution obj;

    string s;

    cout << "Enter string: ";
    cin >> s;

    string result = obj.reverseParentheses(s);

    cout << "Result: " << result << endl;

    return 0;
}