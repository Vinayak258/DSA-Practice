#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int uniqueXorTriplets(vector<int> &nums)
    {
        const int MAXX = 2048;

        vector<bool> dp(MAXX, false);
        dp[0] = true;

        // Choose exactly 3 elements (repetition allowed)
        for (int pick = 0; pick < 3; pick++)
        {
            vector<bool> ndp(MAXX, false);

            for (int x = 0; x < MAXX; x++)
            {
                if (!dp[x])
                    continue;

                for (int num : nums)
                {
                    ndp[x ^ num] = true;
                }
            }

            dp = move(ndp);
        }

        int ans = 0;
        for (bool x : dp)
        {
            if (x)
                ans++;
        }

        return ans;
    }
};

int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    Solution obj;
    cout << obj.uniqueXorTriplets(nums) << endl;

    return 0;
}