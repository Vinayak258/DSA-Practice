#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxSubstring(string &s)
    {
        int currSum = 0;
        int maxSum = -1;

        for (char ch : s)
        {
            int val = (ch == '0') ? 1 : -1;

            currSum = max(val, currSum + val);
            maxSum = max(maxSum, currSum);
        }

        return maxSum;
    }
};

int main()
{
    string s;
    cin >> s;

    Solution obj;
    cout << obj.maxSubstring(s) << endl;

    return 0;
}