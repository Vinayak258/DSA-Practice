#include <iostream>
using namespace std;

class Solution
{

private:
    int max(int a, int b)
    {
        return a > b ? a : b;
    }

public:
    int maxSum(int n)
    {
        // code here.

        if (n == 0)
            return 0;

        int byTwo = maxSum(n / 2);
        int byThree = maxSum(n / 3);
        int byFour = maxSum(n / 4);

        int ans = byTwo + byThree + byFour;

        return max(n, ans);
    }
};

int main()
{

    Solution s1;
    int n;
    cout << "Enter value of n : ";
    cin >> n;

    cout << "Maximun sum is : " << s1.maxSum(n);
    return 0;
}