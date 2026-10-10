
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long minSumSquareDiff(vector<int> &nums1, vector<int> &nums2, int k1, int k2)
    {
        long long k = (long long)k1 + k2;
        int n = nums1.size();

        vector<int> diff(n);
        int mx = 0;
        long long total = 0;

        for (int i = 0; i < n; i++)
        {
            diff[i] = abs(nums1[i] - nums2[i]);
            mx = max(mx, diff[i]);
            total += diff[i];
        }

        if (total <= k)
            return 0;

        int low = 0, high = mx;

        while (low < high)
        {
            int mid = low + (high - low) / 2;
            long long need = 0;

            for (int d : diff)
            {
                if (d > mid)
                    need += d - mid;
            }

            if (need <= k)
                high = mid;
            else
                low = mid + 1;
        }

        int level = low;
        long long ans = 0, used = 0;

        for (int d : diff)
        {
            int reduced = min(d, level);
            ans += 1LL * reduced * reduced;
            used += d - reduced;
        }

        long long remaining = k - used;

        for (int d : diff)
        {
            if (remaining == 0)
                break;

            if (d >= level && level > 0)
            {
                ans -= 2LL * level - 1;
                remaining--;
            }
        }

        return ans;
    }
};

int main()
{
    Solution sol;

    vector<int> nums1 = {1, 4, 10, 12};
    vector<int> nums2 = {5, 8, 6, 9};
    int k1 = 1;
    int k2 = 1;

    cout << sol.minSumSquareDiff(nums1, nums2, k1, k2) << endl;

    return 0;
}
