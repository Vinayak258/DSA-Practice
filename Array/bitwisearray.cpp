#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> minBitwiseArray(vector<int> &nums)
    {
        vector<int> ans;

        for (int n : nums)
        {

            if (n == 2)
            {
                ans.push_back(-1);
                continue;
            }

            int p = (n + 1) & -(n + 1); // lowest set bit of (n + 1)
            ans.push_back(n - (p >> 1));
        }

        return ans;
    }
};

int main()
{
    Solution sol;

    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    vector<int> result = sol.minBitwiseArray(nums);

    for (int x : result)
    {
        cout << x << " ";
    }

    return 0;
}
