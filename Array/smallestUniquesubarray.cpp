
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();

        vector<int> sa(n), rank = nums, newRank(n);
        iota(sa.begin(), sa.end(), 0);

        // Build Suffix Array using Doubling
        for (int k = 1; k < n; k *= 2) {
            sort(sa.begin(), sa.end(), [&](int i, int j) {
                if (rank[i] != rank[j])
                    return rank[i] < rank[j];

                int ri = (i + k < n) ? rank[i + k] : -1;
                int rj = (j + k < n) ? rank[j + k] : -1;

                return ri < rj;
            });

            newRank[sa[0]] = 0;

            for (int i = 1; i < n; i++) {
                int x = sa[i - 1];
                int y = sa[i];

                bool different =
                    rank[x] != rank[y] ||
                    (x + k < n ? rank[x + k] : -1) !=
                    (y + k < n ? rank[y + k] : -1);

                newRank[y] = newRank[x] + different;
            }

            rank = newRank;

            if (rank[sa[n - 1]] == n - 1)
                break;
        }

        // Build LCP Array using Kasai's Algorithm
        vector<int> pos(n), lcp(n, 0);

        for (int i = 0; i < n; i++)
            pos[sa[i]] = i;

        int h = 0;

        for (int i = 0; i < n; i++) {
            int p = pos[i];

            if (p == 0) {
                h = 0;
                continue;
            }

            int j = sa[p - 1];

            while (i + h < n && j + h < n &&
                   nums[i + h] == nums[j + h]) {
                h++;
            }

            lcp[p] = h;

            if (h > 0)
                h--;
        }

        // Find minimum unique subarray length
        int ans = n;

        for (int p = 0; p < n; p++) {
            int mx = lcp[p];

            if (p + 1 < n)
                mx = max(mx, lcp[p + 1]);

            int len = mx + 1;

            if (len <= n - sa[p])
                ans = min(ans, len);
        }

        return ans;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> testCases = {
        {3, 3, 3},
        {2, 1, 2, 3, 3},
        {1, 1, 2, 2, 1},
        {2, 1, 32}
    };

    for (auto nums : testCases) {
        cout << "Input: ";

        for (int x : nums)
            cout << x << " ";

        cout << "\nOutput: "
             << sol.smallestUniqueSubarray(nums)
             << "\n\n";
    }

    return 0;
}
