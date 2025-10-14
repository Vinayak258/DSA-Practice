#include <iostream>
using namespace std;

class Solution
{
public:
    int sum(int n, int &sum1)
    {

        if (n == 0)
            return 0;

        sum1 = n + sum(n - 1, sum1);
        return sum1;
    }
};

int main()
{
    Solution s1;
    int n;
    cout << "Enter number : ";
    cin >> n;

    int sum1 = 0;
    s1.sum(n, sum1);

    cout << "The sum is : " << sum1 << endl;
    return 0;
}