#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> lexicographicallyLargest(vector<int> &arr)
    {
        int n = arr.size();
        int i = 0;

        while (i < n)
        {
            int j = i;

            // Find the contiguous group with the same parity
            while (j + 1 < n &&
                   arr[j] % 2 == arr[j + 1] % 2)
            {
                j++;
            }

            // Sort this group in descending order
            sort(arr.begin() + i, arr.begin() + j + 1,
                 greater<int>());

            i = j + 1;
        }

        return arr;
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
    vector<int> result = obj.lexicographicallyLargest(arr);

    for (int i = 0; i < n; i++)
    {
        cout << result[i];
        if (i < n - 1)
            cout << " ";
    }

    cout << endl;

    return 0;
}