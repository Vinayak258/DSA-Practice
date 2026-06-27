#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumLength(vector<int> &nums)
    {
        unordered_map<long long, int> freq;

        for (int x : nums)
        {
            freq[x]++;
        }

        int ans = 1;

        // Special case for number 1
        if (freq.count(1))
        {
            int ones = freq[1];
            ans = max(ans, (ones % 2 == 0) ? ones - 1 : ones);
        }

        for (auto &[start, cnt] : freq)
        {
            if (start == 1)
                continue;

            long long cur = start;
            int len = 0;

            // Elements on both sides require two occurrences
            while (freq[cur] >= 2)
            {
                len += 2;

                // Prevent overflow
                if (cur > 1000000000LL)
                    break;

                long long next = cur * cur;

                if (!freq.count(next))
                    break;

                cur = next;
            }

            // Use current element as center if available
            if (freq.count(cur) && freq[cur] >= 1)
            {
                len++;
            }
            else if (len > 0)
            {
                // Remove one side element if center does not exist
                len--;
            }

            ans = max(ans, len);
        }

        return ans;
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

    Solution obj;

    cout << obj.maximumLength(nums) << endl;

    return 0;
}