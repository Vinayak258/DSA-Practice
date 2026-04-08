#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int xorAfterQueries(vector<int> &nums, vector<vector<int>> &queries)
    {
        const long long MOD = 1e9 + 7;

        for (auto &q : queries)
        {
            int l = q[0], r = q[1], k = q[2], v = q[3];

            for (int idx = l; idx <= r; idx += k)
            {
                nums[idx] = (1LL * nums[idx] * v) % MOD;
            }
        }

        int ans = 0;
        for (int x : nums)
            ans ^= x;

        return ans;
    }
};

int main()
{
    Solution sol;

    vector<int> nums = {2, 3, 1, 5, 4};
    vector<vector<int>> queries = {
        {1, 4, 2, 3},
        {0, 2, 1, 2}};

    int result = sol.xorAfterQueries(nums, queries);

    cout << "Final XOR: " << result << endl;

    return 0;
}