#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProfit(int x, int y, vector<int> &a, vector<int> &b)
    {
        int n = a.size();

        vector<pair<int, int>> diff;

        // Store absolute difference and index
        for (int i = 0; i < n; i++)
        {
            diff.push_back({abs(a[i] - b[i]), i});
        }

        // Sort in descending order of difference
        sort(diff.begin(), diff.end(), greater<pair<int, int>>());

        int profit = 0;

        for (auto &p : diff)
        {
            int i = p.second;

            // Assign to machine with higher profit if possible
            if ((a[i] >= b[i] && x > 0) || y == 0)
            {
                profit += a[i];
                x--;
            }
            else
            {
                profit += b[i];
                y--;
            }
        }

        return profit;
    }
};

int main()
{
    int n, x, y;

    cout << "Enter number of tasks: ";
    cin >> n;

    vector<int> a(n), b(n);

    cout << "Enter capacity of Machine A and Machine B: ";
    cin >> x >> y;

    cout << "Enter profits for Machine A:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cout << "Enter profits for Machine B:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    Solution obj;

    int ans = obj.maxProfit(x, y, a, b);

    cout << "Maximum Profit = " << ans << endl;

    return 0;
}