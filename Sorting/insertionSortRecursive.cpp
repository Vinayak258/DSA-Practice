#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    void insertionSortRecursion(vector<int> &arr, int n)
    {
        if (n <= 1)
            return;

        insertionSortRecursion(arr, n - 1);

        int last = arr[n - 1];
        int j = n - 2;

        while (j >= 0 && arr[j] > last)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = last;
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

    s1.insertionSortRecursion(arr, 0);
    cout << "After sorting: ";
    for (int i : arr)
    {
        cout << i << " ";
    }

    return 0;
}