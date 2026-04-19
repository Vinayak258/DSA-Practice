#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxDistance(vector<int> &nums1, vector<int> &nums2)
    {
        int i = 0, j = 0;
        int n = nums1.size(), m = nums2.size();
        int ans = 0;

        while (i < n && j < m)
        {
            if (nums1[i] <= nums2[j])
            {
                ans = max(ans, j - i);
                j++; // expand j to maximize distance
            }
            else
            {
                i++; // move i to find smaller nums1[i]
            }
        }

        return ans;
    }
};

int main()
{
    Solution sol;

    // Example test cases
    vector<int> nums1 = {55, 30, 5, 4, 2};
    vector<int> nums2 = {100, 20, 10, 10, 5};

    int result = sol.maxDistance(nums1, nums2);

    cout << "Maximum Distance: " << result << endl;

    return 0;
}