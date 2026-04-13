#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int getMinDistance(vector<int> &nums, int target, int start)
    {
        int ans = INT_MAX;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == target)
            {
                ans = min(ans, abs(i - start));
            }
        }

        return ans;
    }
};

int main()
{
    Solution sol;

    vector<int> nums = {1, 2, 3, 4, 5};
    int target = 5;
    int start = 3;

    cout << sol.getMinDistance(nums, target, start) << endl;

    return 0;
}