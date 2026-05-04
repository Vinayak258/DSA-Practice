#include <iostream>
using namespace std;

class Solution
{
public:
    bool isBinaryPalindrome(int n)
    {
        int original = n;
        int reversed = 0;

        while (n > 0)
        {
            reversed = (reversed << 1) | (n & 1);
            n >>= 1;
        }

        return original == reversed;
    }
};

int main()
{
    int n;
    cin >> n;

    Solution obj;
    if (obj.isBinaryPalindrome(n))
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }

    return 0;
}