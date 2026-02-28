#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findClosestPair(vector<int> &arr1, vector<int> &arr2, int x)
    {
        int n = arr1.size();
        int m = arr2.size();

        int i = 0, j = m - 1;
        int bestDiff = INT_MAX;
        vector<int> ans(2);

        while (i < n && j >= 0)
        {
            int sum = arr1[i] + arr2[j];
            int diff = abs(sum - x);

            if (diff < bestDiff)
            {
                bestDiff = diff;
                ans = {arr1[i], arr2[j]};
            }

            if (sum > x)
                j--;
            else
                i++;
        }

        return ans;
    }
};

int main()
{
    vector<int> arr1 = {1, 4, 5, 7};
    vector<int> arr2 = {10, 20, 30, 40};
    int x = 32;

    Solution sol;
    vector<int> result = sol.findClosestPair(arr1, arr2, x);

    cout << "Closest pair: " << result[0] << " " << result[1] << endl;
    cout << "Absolute difference: "
         << abs(result[0] + result[1] - x) << endl;

    return 0;
}