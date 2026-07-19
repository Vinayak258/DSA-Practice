#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    string smallestSubsequence(string s)
    {
        vector<int> vis(26, 0), num(26, 0);

        // Count frequency of each character
        for (char ch : s)
        {
            num[ch - 'a']++;
        }

        string stk;

        for (char ch : s)
        {
            if (!vis[ch - 'a'])
            {
                while (!stk.empty() && stk.back() > ch)
                {
                    if (num[stk.back() - 'a'] > 0)
                    {
                        vis[stk.back() - 'a'] = 0;
                        stk.pop_back();
                    }
                    else
                    {
                        break;
                    }
                }
                vis[ch - 'a'] = 1;
                stk.push_back(ch);
            }
            num[ch - 'a']--;
        }

        return stk;
    }
};

int main()
{
    Solution obj;

    string s;
    cin >> s;

    cout << obj.smallestSubsequence(s) << endl;

    return 0;
}