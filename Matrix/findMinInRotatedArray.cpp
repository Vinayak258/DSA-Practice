#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMin(vector<int> &nums)
    {

        int low = 0;
        int high = nums.size() - 1;
        int ans = INT_MAX;

        while (low <= high)
        {

            int mid = (low + high) / 2;

            // Left half is sorted
            if (nums[low] <= nums[mid])
            {
                ans = min(ans, nums[low]);
                low = mid + 1;
            }
            // Right half contains minimum
            else
            {
                ans = min(ans, nums[mid]);
                high = mid - 1;
            }
        }

        return ans;
    }
};

int main()
{

    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};

    Solution obj;

    cout << "Minimum element is: " << obj.findMin(nums) << endl;

    return 0;
}