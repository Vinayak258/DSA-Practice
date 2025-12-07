#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int myAtoi(string s)
    {
        int n = s.size();
        int i = 0;

        // 1. Skip leading whitespace
        while (i < n && s[i] == ' ')
            i++;

        // 2. Check sign
        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-'))
        {
            if (s[i] == '-')
                sign = -1;
            i++;
        }

        // 3. Convert digits
        long long num = 0; // to detect overflow
        while (i < n && isdigit(s[i]))
        {
            num = num * 10 + (s[i] - '0');

            // 4. Overflow handling
            if (sign == 1 && num > INT_MAX)
                return INT_MAX;
            if (sign == -1 && -num < INT_MIN)
                return INT_MIN;

            i++;
        }

        return sign * num;
    }
};

int main()
{
    string s;
    // Input usually includes spaces so we use getline
    getline(cin, s);

    Solution obj;
    cout << obj.myAtoi(s) << endl;

    return 0;
}
