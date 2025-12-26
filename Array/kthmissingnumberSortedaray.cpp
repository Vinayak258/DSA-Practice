#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int kthMissing(vector<int> &arr, int k)
    {
        int n = arr.size();
        int low = 0, high = n - 1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            int missing = arr[mid] - (mid + 1);

            if (missing < k)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return low + k;
    }
};

int main()
{
    Solution obj;

    int n, k;
    cin >> n; // size of array
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i]; // array elements
    }

    cin >> k; // kth missing number

    cout << obj.kthMissing(arr, k) << endl;

    return 0;
}
