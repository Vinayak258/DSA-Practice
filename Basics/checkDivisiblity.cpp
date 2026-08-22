#include <iostream>
using namespace std;

class Solution
{
public:
    bool checkDivisibility(int n)
    {
        int temp = n;
        int sum = 0;
        int product = 1;

        while (temp > 0)
        {
            int digit = temp % 10;

            sum += digit;
            product *= digit;

            temp /= 10;
        }

        return n % (sum + product) == 0;
    }
};

int main()
{
    int n;

    cout << "Enter n: ";
    cin >> n;

    Solution obj;

    bool result = obj.checkDivisibility(n);

    if (result)
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }

    return 0;
}