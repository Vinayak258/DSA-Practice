#include <iostream>
using namespace std;

class Solution
{
public:
    bool armstrongNumber(int n)
    {
        // code here

        if (n < 0)
            return false;

        if (n < 10)
            return true;

        int num = n;
        int sum = 0;
        while (num > 0)
        {
            int d = num % 10;
            sum = sum + d * d * d;
            num = num / 10;
        }

        return sum == n;
    }
};

int main()
{

    Solution s1;
    int num;
    cout << "Enter number: ";
    cin >> num;

    if (s1.armstrongNumber(num))
    {
        cout << "Yes , Armstrong number" << endl;
    }
    else
    {
        cout << "No , Not Armstrong number " << endl;
    }
    return 0;
}