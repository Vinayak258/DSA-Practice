#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxFrequency(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        long long total = 0;
        int l = 0, res = 0;

        for (int r = 0; r < nums.size(); ++r)
        {
            total += nums[r];

            // While cost > k, shrink from left
            while ((long long)nums[r] * (r - l + 1) - total > k)
            {
                total -= nums[l];
                l++;
            }

            res = max(res, r - l + 1);
        }
        return res;
    }
};

int main()
{
    Solution s1;
    int k;
    cout << "Enter value of k : ";
    cin >> k;

    vector<int> ans = {1, 4, 8, 13};
    int a = s1.maxFrequency(ans, k);

    cout << "Answer is " << a << endl;
    return 0;
}