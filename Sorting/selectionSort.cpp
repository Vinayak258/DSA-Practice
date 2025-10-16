#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    void selectionSort(vector<int> &arr)
    {
        int n = arr.size();
        int minIndex = -1;

        for (int i = 0; i < n - 1; i++)
        {
            minIndex = i;
            for (int j = i + 1; j < n; j++)
            {
                if (arr[j] < arr[minIndex])
                {
                    minIndex = j;
                }
            }
            swap(arr[i], arr[minIndex]);
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

    s1.selectionSort(arr);

    cout << "After selection sort : ";
    for (int i : arr)
    {
        cout << i << " ";
    }
    return 0;
}