

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &arr, int k)
    {
        int n = arr.size();
        if (n == 0)
            return 0;

        int hold = -arr[0]; // max profit while holding a stock
        int cash = 0;       // max profit without holding a stock

        for (int i = 1; i < n; i++)
        {
            int prevCash = cash;

            // Sell today or keep previous cash
            cash = max(cash, hold + arr[i] - k);

            // Buy today or keep holding previous stock
            hold = max(hold, prevCash - arr[i]);
        }

        return cash;
    }
};

int main()
{
    int n, k;

    // Input size of array
    cin >> n;

    vector<int> arr(n);

    // Input stock prices
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Input transaction fee
    cin >> k;

    Solution obj;
    cout << obj.maxProfit(arr, k) << endl;

    return 0;
}