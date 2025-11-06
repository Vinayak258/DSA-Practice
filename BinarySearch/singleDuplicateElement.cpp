#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        int left = 0, right = nums.size() - 1;

        while (left < right)
        {
            int mid = left + (right - left) / 2;

            // Ensure mid is even so we compare with its pair
            if (mid % 2 == 1)
                mid--;

            if (nums[mid] == nums[mid + 1])
                left = mid + 2; // single element is on the right
            else
                right = mid; // single element is on the left or at mid
        }

        return nums[left];
    }
};

int main()
{
    Solution sol;
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter " << n << " sorted elements:\n";
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    cout << "Single non-duplicate element: "
         << sol.singleNonDuplicate(nums) << endl;

    return 0;
}
