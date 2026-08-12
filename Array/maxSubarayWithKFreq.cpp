#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxSubarrayLength(vector<int> &nums, int k)
    {

        unordered_map<int, int> freq;

        int n = nums.size();
        int i = 0;
        int maxLen = 0;

        for (int j = 0; j < n; j++)
        {

            // Add current element
            freq[nums[j]]++;

            // If frequency becomes greater than k,
            // shrink window from the left
            while (freq[nums[j]] > k)
            {
                freq[nums[i]]--;
                i++;
            }

            // Current window [i ... j] is valid
            maxLen = max(maxLen, j - i + 1);
        }

        return maxLen;
    }
};

int main()
{

    Solution obj;

    int n, k;
    cin >> n >> k;

    vector<int> nums(n);

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    cout << obj.maxSubarrayLength(nums, k) << endl;

    return 0;
}