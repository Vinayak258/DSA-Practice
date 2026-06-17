#include <iostream>
using namespace std;

class Solution
{
public:
    int maxProduct(int n)
    {
        if (n == 2)
            return 1;
        if (n == 3)
            return 2;

        int ans = 1;

        while (n > 4)
        {
            ans *= 3;
            n -= 3;
        }

        return ans * n;
    }
};

int main()
{
    int n;
    cin >> n;

    Solution obj;
    cout << obj.maxProduct(n) << endl;

    return 0;
}