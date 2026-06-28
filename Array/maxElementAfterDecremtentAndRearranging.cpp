#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int> &arr)
    {
        sort(arr.begin(), arr.end());

        arr[0] = 1;

        for (int i = 1; i < arr.size(); i++)
        {
            arr[i] = min(arr[i], arr[i - 1] + 1);
        }

        return arr.back();
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
    cout << obj.maximumElementAfterDecrementingAndRearranging(arr);

    return 0;
}