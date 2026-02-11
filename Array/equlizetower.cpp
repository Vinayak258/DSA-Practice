#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long minCost(vector<int> &heights, vector<int> &cost)
    {
        int n = heights.size();

        vector<pair<int, int>> arr(n);
        for (int i = 0; i < n; i++)
        {
            arr[i] = {heights[i], cost[i]};
        }

        sort(arr.begin(), arr.end());

        long long totalWeight = 0;
        for (int i = 0; i < n; i++)
            totalWeight += arr[i].second;

        long long prefix = 0;
        int target = 0;

        for (int i = 0; i < n; i++)
        {
            prefix += arr[i].second;
            if (prefix >= totalWeight / 2)
            {
                target = arr[i].first;
                break;
            }
        }

        long long ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans += 1LL * abs(heights[i] - target) * cost[i];
        }

        return ans;
    }
};

int main()
{
    int n;
    cin >> n;

    vector<int> heights(n), cost(n);

    for (int i = 0; i < n; i++)
        cin >> heights[i];

    for (int i = 0; i < n; i++)
        cin >> cost[i];

    Solution obj;
    cout << obj.minCost(heights, cost) << endl;

    return 0;
}
