#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxCircularSum(vector<int> &arr)
    {
        int totalSum = 0;
        int maxKadane = arr[0], currMax = arr[0];
        int minKadane = arr[0], currMin = arr[0];

        for (int i = 0; i < arr.size(); i++)
        {
            totalSum += arr[i];

            if (i > 0)
            {
                currMax = max(arr[i], currMax + arr[i]);
                maxKadane = max(maxKadane, currMax);

                currMin = min(arr[i], currMin + arr[i]);
                minKadane = min(minKadane, currMin);
            }
        }

        // All elements are negative
        if (maxKadane < 0)
            return maxKadane;

        return max(maxKadane, totalSum - minKadane);
    }
};

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    Solution obj;
    cout << obj.maxCircularSum(arr) << endl;

    return 0;
}
