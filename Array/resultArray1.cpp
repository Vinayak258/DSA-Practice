#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k, 0);

        // prev[r] = number of subarrays ending at
        // previous index having product % k = r
        vector<long long> prev(k, 0);

        for (int num : nums) {
            vector<long long> curr(k, 0);

            int val = num % k;

            // Start a new subarray with nums[i]
            curr[val]++;

            // Extend all previous subarrays
            for (int r = 0; r < k; r++) {
                if (prev[r] > 0) {
                    int newR = (r * val) % k;
                    curr[newR] += prev[r];
                }
            }

            // Add current subarrays to answer
            for (int r = 0; r < k; r++) {
                ans[r] += curr[r];
            }

            prev = curr;
        }

        return ans;
    }
};

int main() {
    Solution sol;

    int n, k;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Enter k: ";
    cin >> k;

    vector<long long> result = sol.resultArray(nums, k);

    cout << "Result: [";

    for (int i = 0; i < k; i++) {
        cout << result[i];

        if (i != k - 1)
            cout << ", ";
    }

    cout << "]" << endl;

    return 0;
}