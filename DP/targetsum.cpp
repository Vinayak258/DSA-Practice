#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int totalWays(vector<int> &arr, int target)
    {
        int sum = 0;
        for (int x : arr)
            sum += x;

        // If target is not achievable
        if (abs(target) > sum || (sum + target) % 2 != 0)
            return 0;

        int req = (sum + target) / 2;

        vector<int> dp(req + 1, 0);
        dp[0] = 1;

        for (int num : arr)
        {
            for (int j = req; j >= num; j--)
            {
                dp[j] += dp[j - num];
            }
        }

        return dp[req];
    }
};

int main()
{
    int n, target;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cin >> target;

    Solution obj;
    cout << obj.totalWays(arr, target) << endl;

    return 0;
}