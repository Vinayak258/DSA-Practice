#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int sortPermutation(vector<int> &nums)
    {
        int ans = -1;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != i)
            {
                ans &= nums[i];
            }
        }

        return ans == -1 ? 0 : ans;
    }
};

int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    Solution sol;
    cout << sol.sortPermutation(nums) << endl;

    return 0;
}