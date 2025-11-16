#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        int maxProfit = 0;
        int mini = prices[0];
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
    Solution s;
    int n;
    cout << "Enter value of n : ";
    cin >> n;
    cout << endl;
    vector<int> arr(n, 0);
    cout << "Enter elemenet of array : ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Maximum profit is : " << s.maxProfit(arr);

    return 0;
}