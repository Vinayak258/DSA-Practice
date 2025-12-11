#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int splitArray(vector<int> &nums, int k)
    {
        long long left = 0, right = 0;

        for (int x : nums)
        {
            left = max(left, (long long)x);
            right += x;
        }

        while (left < right)
        {
            long long mid = left + (right - left) / 2;

            if (canSplit(nums, k, mid))
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        return left;
    }

private:
    bool canSplit(vector<int> &nums, int k, long long maxSumAllowed)
    {
        long long currSum = 0;
        int parts = 1;

        for (int x : nums)
        {
            if (currSum + x > maxSumAllowed)
            {
                parts++;
                currSum = x;
                if (parts > k)
                    return false;
            }
            else
            {
                currSum += x;
            }
        }
        return true;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    Solution sol;
    int result = sol.splitArray(nums, k);

    cout << result << "\n";

    return 0;
}
