#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minFlips(string s)
    {

        int n = s.size();
        string s2 = s + s;

        int res = INT_MAX;
        int diff1 = 0, diff2 = 0;

        for (int i = 0; i < s2.size(); i++)
        {

            char expected1 = (i % 2) ? '1' : '0'; // pattern 010101...
            char expected2 = (i % 2) ? '0' : '1'; // pattern 101010...

            if (s2[i] != expected1)
                diff1++;
            if (s2[i] != expected2)
                diff2++;

            if (i >= n)
            {
                char prev = s2[i - n];

                char exp1 = ((i - n) % 2) ? '1' : '0';
                char exp2 = ((i - n) % 2) ? '0' : '1';

                if (prev != exp1)
                    diff1--;
                if (prev != exp2)
                    diff2--;
            }

            if (i >= n - 1)
            {
                res = min(res, min(diff1, diff2));
            }
        }

        return res;
    }
};

int main()
{
    string s;

    cout << "Enter binary string: ";
    cin >> s;

    Solution obj;
    int result = obj.minFlips(s);

    cout << "Minimum flips needed: " << result << endl;

    return 0;
}