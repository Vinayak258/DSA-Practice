#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minOperations(vector<int> &nums, int x)
    {
        int n = nums.size();

        long long total = 0;

        // Calculate total sum
        for (int num : nums)
        {
            total += num;
        }

        // We need to keep a subarray with this sum
        long long target = total - x;

        // If target is 0, we have to remove all elements
        if (target == 0)
        {
            return n;
        }

        long long sum = 0;
        int left = 0;
        int maxLen = -1;

        // Sliding Window
        for (int right = 0; right < n; right++)
        {

            sum += nums[right];

            // Shrink window if sum becomes greater than target
            while (left <= right && sum > target)
            {
                sum -= nums[left];
                left++;
            }

            // Found a subarray with required sum
            if (sum == target)
            {
                maxLen = max(maxLen, right - left + 1);
            }
        }

        // No valid subarray found
        if (maxLen == -1)
        {
            return -1;
        }

        // Elements outside the longest subarray are removed
        return n - maxLen;
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

    int x;
    cin >> x;

    Solution obj;

    int ans = obj.minOperations(nums, x);

    cout << ans << endl;

    return 0;
}