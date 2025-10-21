#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    vector<int> rotateByK(vector<int> &arr, int k)
    {
        int n = arr.size();
        k = k % n;
        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++)
        {
            ans[(i + k) % n] = arr[i];
        }
        return ans;
    }

    void inPlaceRotation(vector<int> &arr, int k)
    {
        int n = arr.size();
        k = k % n;

        reverse(arr.begin(), arr.end());
        reverse(arr.begin(), arr.begin() + k);
        reverse(arr.begin() + k, arr.end());
    }
};

int main()
{
    Solution s1;
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Array Before Rotation : ";
    for (int i : arr)
    {
        cout << i << " ";
    }

    int k;
    cout << "Enter k : ";
    cin >> k;

    // vector<int> ans = s1.rotateByK(arr, k);
    s1.inPlaceRotation(arr, k);
    cout << "Array After Rotation : ";
    for (int i : arr)
    {
        cout << i << " ";
    }

    return 0;
}