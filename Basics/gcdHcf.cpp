#include <iostream>
using namespace std;

class Solution
{
public:
    int gcd(int a, int b)
    {

        if (b == 0)
            return a;

        return gcd(b, a % b);
    }
};

int main()
{
    int a, b;
    cout << "Enter a and b : ";
    cin >> a >> b;

    Solution s1;

    int ans = s1.gcd(a, b);
    cout << "GCD of" << a << " and " << b << " is " << s1.gcd(a, b) << endl;

    return 0;
}