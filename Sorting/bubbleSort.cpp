#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    void bubbleSort(vector<int> &arr)
    {
        int n = arr.size();
        bool swapped = false;

        for (int i = 0; i < n - 1; i++)
        {

            swapped = false;
            for (int j = 0; j < n - 1 - i; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    swap(arr[j], arr[j + 1]);
                    swapped = true;
                }
            }

            if (!swapped)
            {
                return;
            }
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

    cout << "Before sorting : ";
    for (int i : arr)
    {
        cout << i << " ";
    }

    cout << endl;

    s1.bubbleSort(arr);

    cout << "After sorting : ";
    for (int i : arr)
    {
        cout << i << " ";
    }

    return 0;
}