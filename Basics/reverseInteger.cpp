#include <iostream>
#include <climits>
using namespace std;

class Solution
{
public:
    int reverse(int x)
    {
        bool isNegative = x < 0;
        long num = (x < 0) ? -(long)x : (long)x;
        long newNum = 0;

        while (num >= 1)
        {
            int d = num % 10;
            newNum = newNum * 10 + d;
            if (newNum > INT_MAX)
                return 0;
            num = num / 10;
        }

        return (isNegative) ? -newNum : newNum;
    }
};

int main()
{
    // cout << "Hello world";

    Solution s1;
    int num;
    cout << "Enter the number : ";
    cin >> num;

    int revNum = s1.reverse(num);
    cout << " The reverse of number is: " << revNum << endl;

    return 0;
}