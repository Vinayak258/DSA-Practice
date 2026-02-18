#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long mergeAndCount(vector<int> &arr, int left, int mid, int right)
    {
        vector<int> temp;
        int i = left;
        int j = mid + 1;
        long long invCount = 0;

        while (i <= mid && j <= right)
        {
            if (arr[i] <= arr[j])
            {
                temp.push_back(arr[i++]);
            }
            else
            {
                temp.push_back(arr[j++]);
                invCount += (mid - i + 1);
            }
        }

        while (i <= mid)
            temp.push_back(arr[i++]);
        while (j <= right)
            temp.push_back(arr[j++]);

        for (int k = 0; k < temp.size(); k++)
            arr[left + k] = temp[k];

        return invCount;
    }

    long long mergeSortAndCount(vector<int> &arr, int left, int right)
    {
        long long invCount = 0;
        if (left < right)
        {
            int mid = left + (right - left) / 2;
            invCount += mergeSortAndCount(arr, left, mid);
            invCount += mergeSortAndCount(arr, mid + 1, right);
            invCount += mergeAndCount(arr, left, mid, right);
        }
        return invCount;
    }

    int inversionCount(vector<int> &arr)
    {
        return (int)mergeSortAndCount(arr, 0, arr.size() - 1);
    }
};

int main()
{
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    Solution obj;
    int result = obj.inversionCount(arr);

    cout << "Inversion Count = " << result << endl;

    return 0;
}
