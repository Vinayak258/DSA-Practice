#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numSteps(string s)
    {
        int steps = 0;
        int carry = 0;

        // Traverse from right to left (excluding MSB)
        for (int i = s.size() - 1; i > 0; --i)
        {
            int bit = (s[i] - '0') + carry;

            if (bit == 1)
            {               // odd
                steps += 2; // add 1 + divide by 2
                carry = 1;
            }
            else
            {               // even (0 or 2)
                steps += 1; // divide by 2
            }
        }

        return steps + carry; // if carry reaches MSB
    }
};

int main()
{
    Solution sol;

    string s;
    cout << "Enter binary string: ";
    cin >> s;

    int result = sol.numSteps(s);
    cout << "Number of steps: " << result << endl;

    return 0;
}