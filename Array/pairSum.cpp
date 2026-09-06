#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long pairAndSum(vector<int> &arr) {
        long long ans = 0;

        // Check each bit
        for (int bit = 0; bit < 31; bit++) {
            long long cnt = 0;

            // Count how many numbers have this bit set
            for (int x : arr) {
                if (x & (1LL << bit)) {
                    cnt++;
                }
            }

            // Choose any 2 numbers having this bit set
            long long pairs = cnt * (cnt - 1) / 2;

            // Add contribution of this bit
            ans += pairs * (1LL << bit);
        }

        return ans;
    }
};

int main() {
    Solution obj;

    vector<int> arr = {5, 10, 15};

    cout << obj.pairAndSum(arr) << endl;

    return 0;
}