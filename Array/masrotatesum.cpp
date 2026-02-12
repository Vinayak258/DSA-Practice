#include <bits/stdc++.h>
using namespace std;

int maxRotateSum(vector<int> &arr)
{
    int n = arr.size();

    int arrSum = 0;
    int currVal = 0;

    for (int i = 0; i < n; i++)
    {
        arrSum += arr[i];
        currVal += i * arr[i];
    }

    int maxVal = currVal;

    for (int i = 1; i < n; i++)
    {
        currVal = currVal + arrSum - n * arr[n - i];
        maxVal = max(maxVal, currVal);
    }

    return maxVal;
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << maxRotateSum(arr) << endl;

    return 0;
}
