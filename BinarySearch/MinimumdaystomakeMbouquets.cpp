#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canMake(vector<int> &bloomDay, int m, int k, int day)
    {
        int bouquets = 0, consec = 0;
        for (int d : bloomDay)
        {
            if (d <= day)
            {
                consec++;
                if (consec == k)
                {
                    bouquets++;
                    consec = 0;
                }
            }
            else
            {
                consec = 0;
            }
            if (bouquets >= m)
                return true;
        }
        return false;
    }

    int minDays(vector<int> &bloomDay, int m, int k)
    {
        long long total = 1LL * m * k;
        if (total > bloomDay.size())
            return -1;

        int left = *min_element(bloomDay.begin(), bloomDay.end());
        int right = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (canMake(bloomDay, m, k, mid))
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
    int n;
    cout << "Enter number of flowers: ";
    cin >> n;

    vector<int> bloomDay(n);
    cout << "Enter bloom days: ";
    for (int i = 0; i < n; i++)
        cin >> bloomDay[i];

    int m, k;
    cout << "Enter m and k: ";
    cin >> m >> k;

    Solution obj;
    int result = obj.minDays(bloomDay, m, k);

    cout << "Minimum days: " << result << endl;
    return 0;
}
