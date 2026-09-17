#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minSumOfLengths(vector<int> &arr, int target)
    {
        int n = arr.size();
        const int INF = 1e9;

        vector<int> best(n + 1, INF);

        int left = 0;
        long long sum = 0;
        int ans = INF;

        for (int right = 0; right < n; right++)
        {
            sum += arr[right];

            // Shrink window if sum becomes greater than target
            while (sum > target)
            {
                sum -= arr[left];
                left++;
            }

            // Current subarray [left ... right] has sum = target
            if (sum == target)
            {
                int len = right - left + 1;

                // Combine with a previous non-overlapping subarray
                if (best[left] != INF)
                {
                    ans = min(ans, best[left] + len);
                }

                // Store the minimum valid length up to right
                best[right + 1] = min(best[right], len);
            }
            else
            {
                best[right + 1] = best[right];
            }
        }

        return (ans == INF) ? -1 : ans;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, target;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cin >> target;

    Solution obj;

    int result = obj.minSumOfLengths(arr, target);

    cout << result << '\n';

    return 0;
}