#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSumWithK(vector<int>& arr, int k) {
        int n = arr.size();

        // maxEnd[i] = Maximum subarray sum ending at index i
        vector<int> maxEnd(n);
        maxEnd[0] = arr[0];

        for (int i = 1; i < n; i++) {
            maxEnd[i] = max(arr[i], maxEnd[i - 1] + arr[i]);
        }

        // Sum of first window of size k
        int windowSum = 0;
        for (int i = 0; i < k; i++) {
            windowSum += arr[i];
        }

        int ans = windowSum;

        // Slide the window
        for (int i = k; i < n; i++) {
            windowSum += arr[i] - arr[i - k];

            // Subarray of exactly size k
            ans = max(ans, windowSum);

            // Extend with best subarray ending before the window
            ans = max(ans, windowSum + maxEnd[i - k]);
        }

        return ans;
    }
};

int main() {
    int n, k;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cin >> k;

    Solution obj;
    cout << obj.maxSumWithK(arr, k) << endl;

    return 0;
}