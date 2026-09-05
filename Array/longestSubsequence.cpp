#include <bits/stdc++.h>
using namespace std;

int longestSubseq(vector<int> &arr)
{
    int maxVal = 1000000;

    // dp[x] = longest valid subsequence ending with value x
    vector<int> dp(maxVal + 2, 0);

    int ans = 0;

    for (int x : arr)
    {
        dp[x] = 1 + max(dp[x - 1], dp[x + 1]);
        ans = max(ans, dp[x]);
    }

    return ans;
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << longestSubseq(arr) << endl;

    return 0;
}