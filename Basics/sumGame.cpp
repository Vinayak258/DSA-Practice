#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool sumGame(string num)
    {
        int n = num.size();

        int diff = 0;
        int leftQ = 0;
        int rightQ = 0;

        // First half
        for (int i = 0; i < n / 2; i++)
        {
            if (num[i] == '?')
            {
                leftQ++;
            }
            else
            {
                diff += num[i] - '0';
            }
        }

        // Second half
        for (int i = n / 2; i < n; i++)
        {
            if (num[i] == '?')
            {
                rightQ++;
            }
            else
            {
                diff -= num[i] - '0';
            }
        }

        // Odd number of '?' -> Alice can always win
        if ((leftQ + rightQ) % 2 == 1)
        {
            return true;
        }

        // Bob can win only if the difference can be exactly balanced
        return diff != (rightQ - leftQ) * 9 / 2;
    }
};

int main()
{
    string num;

    cout << "Enter the string: ";
    cin >> num;

    Solution sol;

    bool result = sol.sumGame(num);

    if (result)
    {
        cout << "Alice wins" << endl;
    }
    else
    {
        cout << "Bob wins" << endl;
    }

    return 0;
}