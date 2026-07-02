#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool divisibleByK(vector<int> &arr, int k)
    {
        vector<bool> dp(k, false);

        for (int x : arr)
        {
            vector<bool> ndp = dp;

            // Start a new subset containing only x
            ndp[x % k] = true;

            // Add x to all previously possible subset sums
            for (int r = 0; r < k; r++)
            {
                if (dp[r])
                {
                    ndp[(r + x) % k] = true;
                }
            }

            // If remainder 0 is achievable, a subset sum is divisible by k
            if (ndp[0])
                return true;

            dp = ndp;
        }

        return false;
    }
};

int main()
{
    int n, k;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter k: ";
    cin >> k;

    Solution obj;

    if (obj.divisibleByK(arr, k))
        cout << "true\n";
    else
        cout << "false\n";

    return 0;
}