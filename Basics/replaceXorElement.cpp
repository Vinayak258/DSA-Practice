#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void replaceElements(vector<int> &arr)
    {
        int n = arr.size();

        // Copy original array
        vector<int> temp = arr;

        // Update first element
        arr[0] = temp[0] ^ temp[1];

        // Update middle elements
        for (int i = 1; i < n - 1; i++)
        {
            arr[i] = temp[i - 1] ^ temp[i + 1];
        }

        // Update last element
        arr[n - 1] = temp[n - 2] ^ temp[n - 1];
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
    obj.replaceElements(arr);

    // Print updated array
    for (int x : arr)
    {
        cout << x << " ";
    }

    return 0;
}