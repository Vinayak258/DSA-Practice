#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canShip(vector<int> &weights, int days, int cap)
    {
        int usedDays = 1, load = 0;
        for (int w : weights)
        {
            if (load + w > cap)
            {
                usedDays++;
                load = 0;
            }
            load += w;
        }
        return usedDays <= days;
    }

    int shipWithinDays(vector<int> &weights, int days)
    {
        int left = *max_element(weights.begin(), weights.end());
        int right = accumulate(weights.begin(), weights.end(), 0);
        int ans = right;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (canShip(weights, days, mid))
            {
                ans = mid;
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return ans;
    }
};

int main()
{
    vector<int> weights;
    int n, days, x;

    cout << "Enter number of packages: ";
    cin >> n;

    cout << "Enter weights: ";
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        weights.push_back(x);
    }

    cout << "Enter number of days: ";
    cin >> days;

    Solution obj;
    cout << "Minimum ship capacity = " << obj.shipWithinDays(weights, days) << endl;

    return 0;
}
