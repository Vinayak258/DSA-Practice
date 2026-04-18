#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxOnes(vector<int> &arr)
    {
        int totalOnes = 0;

        // Count existing 1s
        for (int x : arr)
        {
            if (x == 1)
                totalOnes++;
        }

        // Apply Kadane's Algorithm on transformed values
        int maxGain = 0, curr = 0;

        for (int x : arr)
        {
            int val = (x == 0) ? 1 : -1;

            curr = max(val, curr + val);
            maxGain = max(maxGain, curr);
        }

        return totalOnes + maxGain;
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
    cout << obj.maxOnes(arr) << endl;

    return 0;
}