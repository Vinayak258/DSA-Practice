#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumDistance(vector<int> &nums)
    {
        unordered_map<int, vector<int>> pos;

        for (int i = 0; i < nums.size(); i++)
        {
            pos[nums[i]].push_back(i);
        }

        int ans = INT_MAX;

        for (auto &it : pos)
        {
            vector<int> &v = it.second;

            if (v.size() < 3)
                continue;

            for (int i = 2; i < v.size(); i++)
            {
                ans = min(ans, 2 * (v[i] - v[i - 2]));
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};

int main()
{
    Solution sol;

    vector<int> nums = {1, 2, 1, 1, 3};

    cout << sol.minimumDistance(nums) << endl;

    return 0;
}