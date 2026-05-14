#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isGood(vector<int> &nums)
    {
        int n = *max_element(nums.begin(), nums.end());

        // Size should be n + 1
        if (nums.size() != n + 1)
            return false;

        vector<int> freq(n + 1, 0);

        // Count frequency
        for (int x : nums)
        {
            if (x < 1 || x > n)
                return false;

            freq[x]++;
        }

        // Check 1 to n-1 appear exactly once
        for (int i = 1; i < n; i++)
        {
            if (freq[i] != 1)
                return false;
        }

        // Check n appears exactly twice
        return freq[n] == 2;
    }
};

int main()
{
    Solution obj;

    vector<int> nums = {1, 3, 3, 2};

    if (obj.isGood(nums))
        cout << "true\n";
    else
        cout << "false\n";

    return 0;
}