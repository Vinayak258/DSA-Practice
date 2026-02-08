#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProduct(vector<int> &arr)
    {
        int maxEnd = arr[0];
        int minEnd = arr[0];
        int ans = arr[0];

        for (int i = 1; i < arr.size(); i++)
        {
            int x = arr[i];

            // If current element is negative, swap
            if (x < 0)
            {
                swap(maxEnd, minEnd);
            }

            maxEnd = max(x, maxEnd * x);
            minEnd = min(x, minEnd * x);

            ans = max(ans, maxEnd);
        }

        return ans;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n; // size of array

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    Solution obj;
    cout << obj.maxProduct(arr) << "\n";

    return 0;
}
