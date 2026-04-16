#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int myAtoi(string &s)
    {
        int i = 0, n = s.size();

        // 1) Skip leading whitespaces
        while (i < n && s[i] == ' ')
        {
            i++;
        }

        // 2) Check sign
        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-'))
        {
            if (s[i] == '-')
            {
                sign = -1;
            }
            i++;
        }

        // 3) Read digits and build number
        long long num = 0;

        while (i < n && isdigit(s[i]))
        {
            int digit = s[i] - '0';

            // 4) Check overflow before update
            if (num > (INT_MAX - digit) / 10)
            {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }

            num = num * 10 + digit;
            i++;
        }

        return sign * num;
    }
};

int main()
{
    string s;
    getline(cin, s);

    Solution obj;
    cout << obj.myAtoi(s) << endl;

    return 0;
}