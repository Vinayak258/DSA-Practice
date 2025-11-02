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

            if (nums[low] <= nums[mid])
            {
                ans = min(ans, nums[low]);
                low = mid + 1;
            }
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
    Solution sol;

    vector<int> nums1 = {3, 4, 5, 1, 2};
    cout << "Minimum element: " << sol.findMin(nums1) << endl;

    vector<int> nums2 = {4, 5, 6, 7, 0, 1, 2};
    cout << "Minimum element: " << sol.findMin(nums2) << endl;

    vector<int> nums3 = {11, 13, 15, 17};
    cout << "Minimum element: " << sol.findMin(nums3) << endl;

    return 0;
}
