#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isBitSet(int n)
    {
        // If n is 0, return false
        if (n == 0)
            return false;

        // Check if all bits are set
        return (n & (n + 1)) == 0;
    }
};

int main()
{
    int n;
    cin >> n;

    Solution obj;

    if (obj.isBitSet(n))
        cout << "true";
    else
        cout << "false";

    return 0;
}