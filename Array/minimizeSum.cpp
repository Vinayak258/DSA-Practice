
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimizeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());

        int n = nums.size();

        return min({nums[n - 1] - nums[2],
                    nums[n - 2] - nums[1],
                    nums[n - 3] - nums[0]});
    }
};

int main()
{
    Solution obj;

    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    cout << obj.minimizeSum(nums) << endl;

    return 0;
}
