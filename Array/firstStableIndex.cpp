#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int firstStableIndex(vector<int> &nums, int k)
    {
        int n = nums.size();

        // suffixMin[i] = minimum element from i to n-1
        vector<int> suffixMin(n);

        suffixMin[n - 1] = nums[n - 1];

        for (int i = n - 2; i >= 0; i--)
        {
            suffixMin[i] = min(nums[i], suffixMin[i + 1]);
        }

        // prefixMax = maximum element from 0 to i
        int prefixMax = nums[0];

        for (int i = 0; i < n; i++)
        {

            prefixMax = max(prefixMax, nums[i]);

            // Instability score
            int instability = prefixMax - suffixMin[i];

            // First stable index
            if (instability <= k)
            {
                return i;
            }
        }

        return -1;
    }
};

int main()
{

    Solution sol;

    // Test Case 1
    vector<int> nums = {5, 0, 1, 4};
    int k = 3;

    int answer = sol.firstStableIndex(nums, k);

    cout << "Smallest Stable Index = " << answer << endl;

    return 0;
}