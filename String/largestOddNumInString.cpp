#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string largestOddNumber(string num)
    {
        for (int i = num.size() - 1; i >= 0; --i)
        {
            int digit = num[i] - '0';
            if (digit % 2 == 1)
            {
                return num.substr(0, i + 1);
            }
        }
        return "";
    }
};

int main()
{
    Solution sol;
    string num;

    cout << "Enter a numeric string: ";
    cin >> num;

    string result = sol.largestOddNumber(num);

    if (result.empty())
        cout << "No odd number exists in the string." << endl;
    else
        cout << "Largest odd number substring: " << result << endl;

    return 0;
}
