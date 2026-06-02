#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int sumDiffPairs(vector<int> &arr, int k)
    {
        int n = arr.size();

        // Sort the array
        sort(arr.begin(), arr.end());

        int ans = 0;

        // Traverse from the end
        for (int i = n - 1; i > 0; i--)
        {

            // Check if pair difference is less than k
            if (arr[i] - arr[i - 1] < k)
            {

                // Add pair sum
                ans += arr[i] + arr[i - 1];

                // Skip the next element since pairs must be disjoint
                i--;
            }
        }

        return ans;
    }
};

int main()
{
    int n, k;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter k: ";
    cin >> k;

    Solution obj;

    int result = obj.sumDiffPairs(arr, k);

    cout << "Maximum pair sum = " << result << endl;

    return 0;
}