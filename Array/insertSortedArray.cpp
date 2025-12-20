#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int searchInsertK(vector<int> &arr, int k)
    {
        int low = 0, high = arr.size() - 1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (arr[mid] == k)
                return mid;
            else if (arr[mid] < k)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return low; // insertion position
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

    int k;
    cin >> k;

    Solution obj;
    cout << obj.searchInsertK(arr, k) << endl;

    return 0;
}
