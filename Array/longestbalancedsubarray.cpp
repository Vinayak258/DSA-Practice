#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestBalancedSubarray(vector<int> &nums)
    {
        int n = nums.size();
        int ans = 0;

        for (int l = 0; l < n; l++)
        {
            unordered_set<int> evenSet, oddSet;

            for (int r = l; r < n; r++)
            {
                if (nums[r] % 2 == 0)
                    evenSet.insert(nums[r]);
                else
                    oddSet.insert(nums[r]);

                if (evenSet.size() == oddSet.size())
                {
                    ans = max(ans, r - l + 1);
                }
            }
        }
        return ans;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n; // number of elements

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i]; // array elements
    }

    Solution sol;
    cout << sol.longestBalancedSubarray(nums) << "\n";

    return 0;
}
