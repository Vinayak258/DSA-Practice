#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxSumSubarray(vector<int> &arr)
    {
        int n = arr.size();

        vector<int> pre(n), suff(n);

        // Maximum subarray sum ending at i
        pre[0] = arr[0];
        for (int i = 1; i < n; i++)
        {
            pre[i] = max(arr[i], pre[i - 1] + arr[i]);
        }

        // Maximum subarray sum starting at i
        suff[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            suff[i] = max(arr[i], suff[i + 1] + arr[i]);
        }

        // Case when no deletion is performed
        int ans = *max_element(pre.begin(), pre.end());

        // Try deleting each middle element
        for (int i = 1; i < n - 1; i++)
        {
            ans = max(ans, pre[i - 1] + suff[i + 1]);
        }

        return ans;
    }
};

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    Solution obj;
    cout << obj.maxSumSubarray(arr) << endl;

    return 0;
}