#include <bits/stdc++.h>
using namespace std;

int maxSubarrayXOR(vector<int> &arr, int k)
{
    int n = arr.size();
    int curr = 0;

    // XOR of first window
    for (int i = 0; i < k; i++)
    {
        curr ^= arr[i];
    }

    int ans = curr;

    // Sliding window
    for (int i = k; i < n; i++)
    {
        curr ^= arr[i - k]; // remove element leaving window
        curr ^= arr[i];     // add new element
        ans = max(ans, curr);
    }

    return ans;
}

int main()
{
    vector<int> arr = {2, 5, 8, 1, 1, 3};
    int k = 3;

    cout << maxSubarrayXOR(arr, k);

    return 0;
}