#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findKRotation(vector<int> &arr)
    {
        // Code Here

        if (arr.size() == 1)
            return 0;

        // int ans = 0;
        int i = 0;

        while (i < arr.size() - 1 && arr[i] < arr[i + 1])
        {
            i++;
        }

        if (i == arr.size() - 1)
        {
            return 0;
        }

        return (i + 1) % arr.size();
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        cout << ob.findKRotation(arr) << endl;
    }
    return 0;
}
