#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int cntWays(vector<int> &arr)
    {
        int n = arr.size();

        int totalEven = 0, totalOdd = 0;

        // Total sums at even and odd indices
        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 0)
                totalEven += arr[i];
            else
                totalOdd += arr[i];
        }

        int leftEven = 0, leftOdd = 0;
        int count = 0;

        // Check each index removal
        for (int i = 0; i < n; i++)
        {
            int rightEven = totalEven - leftEven;
            int rightOdd = totalOdd - leftOdd;

            if (i % 2 == 0)
                rightEven -= arr[i];
            else
                rightOdd -= arr[i];

            int newEvenSum = leftEven + rightOdd;
            int newOddSum = leftOdd + rightEven;

            if (newEvenSum == newOddSum)
                count++;

            // Update prefix sums
            if (i % 2 == 0)
                leftEven += arr[i];
            else
                leftOdd += arr[i];
        }

        return count;
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
    cout << obj.cntWays(arr) << endl;

    return 0;
}
