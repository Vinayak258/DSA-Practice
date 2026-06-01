#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumCost(vector<int> &cost)
    {

        // Sort in descending order
        sort(cost.begin(), cost.end(), greater<int>());

        int ans = 0;

        for (int i = 0; i < cost.size(); i++)
        {

            // Every 3rd candy is free
            if ((i + 1) % 3 != 0)
            {
                ans += cost[i];
            }
        }

        return ans;
    }
};

int main()
{

    int n;
    cin >> n;

    vector<int> cost(n);

    for (int i = 0; i < n; i++)
    {
        cin >> cost[i];
    }

    Solution obj;

    cout << obj.minimumCost(cost);

    return 0;
}