
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        int n = nums.size();

        int zero = find(nums.begin(), nums.end(), 0) - nums.begin();

        auto check = [&](int step)
        {
            for (int i = 1; i < n; i++)
            {
                int prev = (zero + (i - 1) * step + n) % n;
                int curr = (zero + i * step + n) % n;

                if (nums[prev] > nums[curr])
                {
                    return false;
                }
            }
            return true;
        };

        int ans = INT_MAX;

        // Increasing cyclic order
        if (check(1))
        {
            ans = min(ans, zero);
            ans = min(ans, n - zero + 2);
        }

        // Decreasing cyclic order
        if (check(-1))
        {
            ans = min(ans, zero + 2);
            ans = min(ans, n - zero);
        }

        return ans == INT_MAX ? -1 : ans;
    }
};

int main()
{
    Solution sol;

    vector<int> nums1 = {0, 2, 1};
    cout << sol.minOperations(nums1) << endl; // Output: 2

    vector<int> nums2 = {1, 0, 2};
    cout << sol.minOperations(nums2) << endl; // Output: 2

    vector<int> nums3 = {2, 0, 1, 3};
    cout << sol.minOperations(nums3) << endl; // Output: -1

    return 0;
}
