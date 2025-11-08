#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        int left = 0, right = nums.size() - 1;

        while (left < right)
        {
            int mid = left + (right - left) / 2;

            if (nums[mid] > nums[mid + 1])
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
};

int main()
{
    Solution sol;

    // Example 1
    vector<int> nums1 = {1, 2, 3, 1};
    cout << "Peak index for [1,2,3,1]: " << sol.findPeakElement(nums1) << endl;

    // Example 2
    vector<int> nums2 = {1, 2, 1, 3, 5, 6, 4};
    cout << "Peak index for [1,2,1,3,5,6,4]: " << sol.findPeakElement(nums2) << endl;

    // Custom test
    vector<int> nums3 = {10, 20, 15, 2, 23, 90, 67};
    cout << "Peak index for [10,20,15,2,23,90,67]: " << sol.findPeakElement(nums3) << endl;

    return 0;
}
