#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void sort012(vector<int> &arr)
    {
        int low = 0, mid = 0, high = arr.size() - 1;

        while (mid <= high)
        {
            if (arr[mid] == 0)
            {
                swap(arr[low], arr[mid]);
                low++;
                mid++;
            }
            else if (arr[mid] == 1)
            {
                mid++;
            }
            else
            { // arr[mid] == 2
                swap(arr[mid], arr[high]);
                high--;
            }
        }
    }
};

int main()
{
    int n;
    cin >> n; // size of array

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i]; // array elements (0,1,2)
    }

    Solution obj;
    obj.sort012(arr);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
