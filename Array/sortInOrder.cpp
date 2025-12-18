#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void sortIt(vector<int> &arr)
    {
        vector<int> odd, even;

        // Separate odd and even numbers
        for (int x : arr)
        {
            if (x % 2 == 0)
                even.push_back(x);
            else
                odd.push_back(x);
        }

        // Sort odd in descending order
        sort(odd.begin(), odd.end(), greater<int>());

        // Sort even in ascending order
        sort(even.begin(), even.end());

        // Merge back into original array
        int index = 0;
        for (int x : odd)
            arr[index++] = x;
        for (int x : even)
            arr[index++] = x;
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
    obj.sortIt(arr);

    for (int x : arr)
    {
        cout << x << " ";
    }

    return 0;
}
