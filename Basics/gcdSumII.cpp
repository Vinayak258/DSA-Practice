#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long gcdSum(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> prefixGcd(n);

        int mx = 0;
        for (int i = 0; i < n; i++)
        {
            mx = max(mx, nums[i]);
            prefixGcd[i] = gcd(nums[i], mx);
        }

        sort(prefixGcd.begin(), prefixGcd.end());

        long long ans = 0;
        int l = 0, r = n - 1;

        while (l < r)
        {
            ans += gcd(prefixGcd[l], prefixGcd[r]);
            l++;
            r--;
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
    cout << obj.gcdSum(nums) << endl;

    return 0;
}