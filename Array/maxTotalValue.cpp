#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long maxTotalValue(vector<int> &nums, int k)
    {
        int mn = INT_MAX;
        int mx = INT_MIN;

        for (int x : nums)
        {
            mn = min(mn, x);
            mx = max(mx, x);
        }

        return 1LL * (mx - mn) * k;
    }
};

int main()
{
    int n, k;

    // Input size of array
    cin >> n;

    vector<int> nums(n);

    // Input array elements
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    // Input k
    cin >> k;

    Solution obj;

    cout << obj.maxTotalValue(nums, k) << endl;

    return 0;
}