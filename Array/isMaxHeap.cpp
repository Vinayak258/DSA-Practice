#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isMaxHeap(vector<int> &arr)
    {
        int n = arr.size();

        // Check all non-leaf nodes
        for (int i = 0; i <= (n / 2) - 1; i++)
        {
            int left = 2 * i + 1;
            int right = 2 * i + 2;

            if (left < n && arr[i] < arr[left])
                return false;

            if (right < n && arr[i] < arr[right])
                return false;
        }
        return true;
    }
};

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    Solution obj;
    if (obj.isMaxHeap(arr))
    {
        cout << "Yes, it is a Max Heap\n";
    }
    else
    {
        cout << "No, it is not a Max Heap\n";
    }

    return 0;
}