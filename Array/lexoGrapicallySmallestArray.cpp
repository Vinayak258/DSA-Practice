#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> lexicographicallySmallestArray(vector<int> &nums, int limit)
    {
        int n = nums.size();

        // Store {value, original index}
        vector<pair<int, int>> a;

        for (int i = 0; i < n; i++)
        {
            a.push_back({nums[i], i});
        }

        // Sort by value
        sort(a.begin(), a.end());

        vector<int> ans(n);

        int i = 0;

        while (i < n)
        {
            int j = i;

            // Find the end of the current group
            while (j + 1 < n &&
                   a[j + 1].first - a[j].first <= limit)
            {
                j++;
            }

            // Collect original indices of this group
            vector<int> indices;

            for (int k = i; k <= j; k++)
            {
                indices.push_back(a[k].second);
            }

            // Put values into indices in sorted order
            sort(indices.begin(), indices.end());

            for (int k = 0; k < (int)indices.size(); k++)
            {
                ans[indices[k]] = a[i + k].first;
            }

            // Move to the next group
            i = j + 1;
        }

        return ans;
    }
};

int main()
{
    Solution sol;

    // Example 1
    vector<int> nums = {1, 5, 3, 9, 8};
    int limit = 2;

    vector<int> ans = sol.lexicographicallySmallestArray(nums, limit);

    cout << "Answer: ";

    for (int x : ans)
    {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}