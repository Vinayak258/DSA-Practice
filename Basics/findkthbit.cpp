#include <iostream>
using namespace std;

class Solution
{
public:
    char findKthBit(int n, int k)
    {
        if (n == 1)
            return '0';

        int mid = 1 << (n - 1); // 2^(n-1)

        if (k == mid)
            return '1';
        else if (k < mid)
            return findKthBit(n - 1, k);
        else
        {
            // Mirror index in left half
            char bit = findKthBit(n - 1, (1 << n) - k);
            // Invert the bit
            return (bit == '0') ? '1' : '0';
        }
    }
};

int main()
{
    int n, k;

    cout << "Enter n: ";
    cin >> n;

    cout << "Enter k: ";
    cin >> k;

    Solution sol;
    char result = sol.findKthBit(n, k);

    cout << "The " << k << "th bit in S" << n << " is: " << result << endl;

    return 0;
}