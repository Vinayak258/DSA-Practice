#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int firstOccourence(vector<int> &nums, int target)
    {
        int n = nums.size();
        int i = 0;
        int j = n - 1;
        int sindex = -1;

        while (i <= j)
        {
            int mid = (i + j) / 2;

            if (nums[mid] == target)
            {
                sindex = mid;
                j = mid - 1;
            }
            else if (nums[mid] > target)
            {
                j = mid - 1;
            }
            else
            {
                i = mid + 1;
            }
        }
        return sindex;
    }

    int LastOccourence(vector<int> &nums, int target)
    {
        int n = nums.size();
        int i = 0;
        int j = n - 1;
        int lindex = -1;

        while (i <= j)
        {
            int mid = (i + j) / 2;

            if (nums[mid] == target)
            {
                lindex = mid;
                i = mid + 1;
            }
            else if (nums[mid] > target)
            {
                j = mid - 1;
            }
            else
            {
                i = mid + 1;
            }
        }
        return lindex;
    }

    vector<int> searchRange(vector<int> &nums, int target)
    {
        int sIndex = firstOccourence(nums, target);
        int fIndex = LastOccourence(nums, target);
        return {sIndex, fIndex};
    }
};

int main()
{
    Solution sol;
    int n, target;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements (sorted order): ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    cout << "Enter target: ";
    cin >> target;

    vector<int> result = sol.searchRange(nums, target);

    cout << "First and Last Occurrence Indices: ["
         << result[0] << ", " << result[1] << "]" << endl;

    return 0;
}
