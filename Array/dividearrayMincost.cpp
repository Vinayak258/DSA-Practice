#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumCost(vector<int> &nums)
    {
        int n = nums.size();

        int ans = INT_MAX;
        int minSecond = nums[1];

        for (int j = 2; j < n; j++)
        {
            ans = min(ans, nums[0] + minSecond + nums[j]);
            minSecond = min(minSecond, nums[j]);
        }

        return ans;
    }
};

int main()
{
    Solution sol;

    int n;
    cin >> n; // size of array

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i]; // array elements
    }

    cout << sol.minimumCost(nums) << endl;

    return 0;
}
