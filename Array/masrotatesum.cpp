#include <bits/stdc++.h>
using namespace std;

int maxRotateSum(vector<int> &arr)
{
    int n = arr.size();

    int arrSum = 0;  // Sum of all array elements
    int currVal = 0; // Value of sum(i * arr[i]) for current rotation

    // Calculate arrSum and initial currVal
    for (int i = 0; i < n; i++)
    {
        arrSum += arr[i];
        currVal += i * arr[i];
    }

    int maxVal = currVal;

    // Compute values for other rotations
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
