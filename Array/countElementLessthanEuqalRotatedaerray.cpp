#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countLessEqual(vector<int> &arr, int x)
    {
        int n = arr.size();
        int low = 0, high = n - 1;

        // Find rotation pivot (minimum element index)
        while (low < high)
        {
            int mid = low + (high - low) / 2;
            if (arr[mid] > arr[high])
                low = mid + 1;
            else
                high = mid;
        }
        int pivot = low;

        // Count elements <= x in both sorted halves
        int count = 0;
        count += upper_bound(arr.begin(), arr.begin() + pivot, x) - arr.begin();
        count += upper_bound(arr.begin() + pivot, arr.end(), x) - (arr.begin() + pivot);

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

    int x;
    cin >> x;

    Solution obj;
    cout << obj.countLessEqual(arr, x) << endl;

    return 0;
}
