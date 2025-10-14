#include <iostream>
using namespace std;

class Solution
{
public:
    int fact(int n)
    {

        if (n == 1)
            return 1;

        return n * fact(n - 1);
    }
};

int main()
{
    int n;
    cout << "Enter number  : ";
    cin >> n;

    Solution s1;
    cout << "The factorial is : " << s1.fact(n) << endl;

    return 0;
}