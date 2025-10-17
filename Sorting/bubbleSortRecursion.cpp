#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    void bubbleSortRecursion(vector<int> &arr, int i)
    {
        if (i >= arr.size() - 1)
            return;

        bool swapped = false;
        for (int j = 0; j < arr.size() - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        if (!swapped)
            return;
        else
        {
            bubbleSortRecursion(arr, i + 1);
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

    s1.bubbleSortRecursion(arr, 0);
    cout << "After sorting: ";
    for (int i : arr)
    {
        cout << i << " ";
    }

    return 0;
}