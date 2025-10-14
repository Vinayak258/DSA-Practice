#include <iostream>
using namespace std;

class Solution
{
public:
    void solve(int arr[], int i, int n)
    {

        if (i >= n / 2)
            return;

        swap(arr[i], arr[n - i - 1]);
        i++;
        solve(arr, i, n);
    }
    void reverse(int arr[], int n)
    {
        if (n <= 1)
            return;
        int i = 0;
        solve(arr, i, n);
    }
};

int main()
{

    Solution s1;
    int arr[] = {1, 2, 5, 7, 5, 8, 5, 0, 10, 59};
    int n = sizeof(arr) / sizeof(arr[0]);

    s1.solve(arr, 0, n);

    for (int i : arr)
    {
        cout << i << " ";
    }
    return 0;
}