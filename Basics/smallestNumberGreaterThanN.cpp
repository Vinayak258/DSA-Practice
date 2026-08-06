#include <iostream>
using namespace std;

class Solution
{
public:
    int digitProduct(int x)
    {
        int product = 1;

        while (x > 0)
        {
            product *= (x % 10);
            x /= 10;
        }

        return product;
    }

    int smallestNumber(int n, int t)
    {
        while (true)
        {
            if (digitProduct(n) % t == 0)
                return n;
            n++;
        }
    }
};

int main()
{
    Solution obj;

    int n, t;

    cout << "Enter n and t: ";
    cin >> n >> t;

    int ans = obj.smallestNumber(n, t);

    cout << "Smallest number = " << ans << endl;

    return 0;
}