#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double myPow(double x, int n)
    {
        long long power = n; // convert to long long to handle n = -2^31 safely
        return helper(x, power);
    }

    double helper(double x, long long n)
    {
        if (n == 0)
            return 1.0;
        if (n < 0)
            return 1.0 / helper(x, -n);

        double half = helper(x, n / 2);

        if (n % 2 == 0)
            return half * half;
        else
            return x * half * half;
    }
};

int main()
{
    double x;
    int n;
    cout << "Enter base x: ";
    cin >> x;
    cout << "Enter exponent n: ";
    cin >> n;

    Solution obj;
    double result = obj.myPow(x, n);

    cout << "Result: " << fixed << setprecision(5) << result << endl;

    return 0;
}
