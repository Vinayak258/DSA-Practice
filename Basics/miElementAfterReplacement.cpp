#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int digitSum(int n)
    {
        int sum = 0;

        while (n > 0)
        {
            sum += n % 10;
            n /= 10;
        }

        return sum;
    }

    int minElement(vector<int> &nums)
    {
        int ans = INT_MAX;

        for (int x : nums)
        {
            ans = min(ans, digitSum(x));
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

    cout << obj.minElement(nums) << endl;

    return 0;
}