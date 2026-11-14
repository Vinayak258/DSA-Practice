
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumSumSubarray(vector<int> &nums, int l, int r)
    {

        int n = nums.size();
        int ans = INT_MAX;

        for (int i = 0; i < n; i++)
        {

            int sum = 0;

            for (int j = i; j < n && j < i + r; j++)
            {

                sum += nums[j];

                int len = j - i + 1;

                if (len >= l && len <= r && sum > 0)
                {
                    ans = min(ans, sum);
                }
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};

int main()
{

    Solution obj;

    int n, l, r;

    cout << "Enter array size: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    cout << "Enter l and r: ";
    cin >> l >> r;

    int result = obj.minimumSumSubarray(nums, l, r);

    cout << "Minimum Positive Sum: " << result << endl;

    return 0;
}
