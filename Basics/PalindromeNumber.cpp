#include <iostream>
#include <climits>
using namespace std;

class Solution
{
public:
    bool isPalindrome(int num)
    {
        if (num < 0)
            return false;
        long x = (long)num;
        long newNum = 0;

        while (x > 0)
        {
            int d = x % 10;
            newNum = newNum * 10 + d;
            x = x / 10;
        }
        return num == newNum;
    }
};

int main()
{

    int num;
    cout << "Enter number : ";
    cin >> num;

    Solution s1;

    if (s1.isPalindrome(num))
    {
        cout << "Yes, Number is Palindrome" << endl;
    }
    else
    {
        cout << "No, Number is not palindrome" << endl;
    }

    return 0;
}