#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    void moveZero(vector<int> &arr)
    {
        int n = arr.size();
        int j = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] != 0)
            {
                swap(arr[j], arr[i]);
                j++;
            }
        }
    }
};

int main()
{
    Solution s1;
    int n;
    cout << "Enter size of n : ";
    cin >> n;

    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << endl;

    cout << "Before moving zero : ";
    for (int i : arr)
    {
        cout << i << " ";
    }
    s1.moveZero(arr);
    cout << "After moving zero : ";
    for (int i : arr)
    {
        cout << i << " ";
    }
    return 0;
}