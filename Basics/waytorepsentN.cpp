#include <iostream>
using namespace std;

class Solution
{
public:
    int getCount(int n)
    {
        int cnt = 0;
        long long twoN = 2LL * n;

        // Try every possible length of consecutive sequence
        for (long long k = 2; k * (k + 1) / 2 <= n; k++)
        {

            // 2n must be divisible by k
            if (twoN % k == 0)
            {

                // t = 2 * starting number
                long long t = twoN / k - k + 1;

                // Starting number must be a positive integer
                if (t > 0 && t % 2 == 0)
                    cnt++;
            }
        }

        return cnt;
    }
};

int main()
{
    int n;
    cin >> n;

    Solution obj;
    cout << obj.getCount(n) << endl;

    return 0;
}