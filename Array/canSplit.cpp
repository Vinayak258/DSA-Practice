#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canSplit(vector<int> &arr)
    {
        long long total = 0;

        // Calculate total sum
        for (int x : arr)
        {
            total += x;
        }

        // If total sum is odd, can't split equally
        if (total % 2 != 0)
            return false;

        long long prefix = 0;
        long long target = total / 2;

        // Check for prefix sum equal to half
        for (int i = 0; i < arr.size(); i++)
        {
            prefix += arr[i];
            if (prefix == target)
                return true;
        }

        return false;
    }
};

int main()
{
    Solution obj;

    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    if (obj.canSplit(arr))
    {
        cout << "true\n";
    }
    else
    {
        cout << "false\n";
    }

    return 0;
}