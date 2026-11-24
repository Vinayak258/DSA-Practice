
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            __int128 prod = 1;
            long long g = 0;
            long long l = 1;

            for (int j = i; j < n; j++) {
                prod *= nums[j];

                g = gcd(g, (long long)nums[j]);
                l = lcm(l, (long long)nums[j]);

                if (prod == (__int128)g * l) {
                    ans = max(ans, j - i + 1);
                }
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {1, 2, 1, 2, 1, 1, 1};

    cout << "Maximum Length: "
         << sol.maxLength(nums) << endl;

    return 0;
}
