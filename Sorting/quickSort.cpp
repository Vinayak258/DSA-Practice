#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int partition(vector<int> &arr, int low, int high)
    {
        int pivot = arr[high];
        int i = low - 1;

        for (int j = low; j < high; j++)
        {
            if (arr[j] <= pivot)
            {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        return i + 1;
    }

    void quickSort(vector<int> &arr, int low, int high)
    {
        if (low < high)
        {
            int pi = partition(arr, low, high);
            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
    }
};
int main()
{
    int n;
    cout << "Enter size : ";
    cin >> n;
    vector<int> arr(n, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Before sorting: ";
    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << endl;

    Solution s1;

    s1.quickSort(arr, 0, arr.size() - 1);
    cout << "After sorting: ";
    for (int i : arr)
    {
        cout << i << " ";
    }

    return 0;
}