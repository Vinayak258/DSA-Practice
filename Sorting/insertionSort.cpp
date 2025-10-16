#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    void insertionSort(vector<int> &arr)
    {
        int n = arr.size();
        for (int i = 1; i < n; i++)
        {
            int key = arr[i];
            int j = i - 1;

            while (j >= 0 && arr[j] > key)
            {
                arr[j + 1] = arr[j];
                j = j - 1;
            }

            arr[j + 1] = key;
        }
    }
};

int main()
{
    Solution s1;
    int n;
    cout << "Enter size of array : ";
    cin >> n;

    vector<int> arr(n, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Before selection sort : ";
    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << endl;

    s1.insertionSort(arr);

    cout << "After selection sort : ";
    for (int i : arr)
    {
        cout << i << " ";
    }
    return 0;
}