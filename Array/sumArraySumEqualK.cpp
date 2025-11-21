#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int count = 0;
        int n = nums.size();
        vector<int> prefixSum(n, 0);
        prefixSum[0] = nums[0];

        for (int i = 1; i < n; i++)
        {
            prefixSum[i] = prefixSum[i - 1] + nums[i];
        }

        unordered_map<int, int> mp;

        for (int j = 0; j < n; j++)
        {
            if (prefixSum[j] == k)
            {
                count++;
            }
            int val = prefixSum[j] - k;
            if (mp.find(val) != mp.end())
            {
                count += mp[val];
            }
            mp[prefixSum[j]]++;
        }

        return count;
    }
};

int main()
{
    vector<int> nums;
    int n, k;

    cout << "Enter number of elements: ";
    cin >> n;

    nums.resize(n);
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    cout << "Enter k: ";
    cin >> k;

    Solution sol;
    int result = sol.subarraySum(nums, k);

    cout << "Number of subarrays whose sum = " << k << " is: " << result << endl;

    return 0;
}
