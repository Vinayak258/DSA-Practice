#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int mini = prices[0];
        int maxProfit = 0;
        int n = prices.size();

        for (int i = 1; i < n; i++)
        {
            int cost = prices[i] - mini;
            maxProfit = max(maxProfit, cost);
            mini = min(mini, prices[i]);
        }
        return maxProfit;
    }
};

int main()
{
    Solution obj;

    vector<int> test1 = {7, 1, 5, 3, 6, 4};
    vector<int> test2 = {7, 6, 4, 3, 1};
    vector<int> test3 = {1, 2, 3, 4, 5};
    vector<int> test4 = {3, 8, 1, 9};

    cout << "Test 1 Profit: " << obj.maxProfit(test1) << endl; // Expected: 5
    cout << "Test 2 Profit: " << obj.maxProfit(test2) << endl; // Expected: 0
    cout << "Test 3 Profit: " << obj.maxProfit(test3) << endl; // Expected: 4
    cout << "Test 4 Profit: " << obj.maxProfit(test4) << endl; // Expected: 8

    return 0;
}
