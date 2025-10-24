#include <vector>
#include <climits>
#include <iostream>
using namespace std;

int kadaneMaxSubarraySum(vector<int> &arr)
{
    int currentSum = 0;
    int maxSum = INT_MIN;

    for (int x : arr)
    {
        currentSum = max(x, currentSum + x);
        maxSum = max(maxSum, currentSum);
    }

    return maxSum;
}

int main()
{
    int n;
    cout << "Enter size of subarray : ";
    cin >> n;

    vector<int> arr(n, 0);
    cout << "Enter array element : ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << kadaneMaxSubarraySum(arr);
    return 0;
}