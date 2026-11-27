
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();

        // Calculate free items for each item type
        vector<int> bonus(n, 0);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j && items[j][0] % items[i][0] == 0) {
                    bonus[i]++;
                }
            }
        }

        const int NEG = -1e9;

        // DP for maximum items with exact spending
        vector<int> dp(budget + 1, NEG);
        dp[0] = 0;

        for (int i = 0; i < n; i++) {
            int price = items[i][1];
            int value = 1 + bonus[i];

            vector<int> take(budget + 1, NEG);

            for (int b = price; b <= budget; b++) {

                // First purchased copy (includes free items)
                if (dp[b - price] != NEG) {
                    take[b] = max(take[b],
                                  dp[b - price] + value);
                }

                // Additional purchased copies
                if (take[b - price] != NEG) {
                    take[b] = max(take[b],
                                  take[b - price] + 1);
                }
            }

            // Update answer for each budget
            for (int b = 0; b <= budget; b++) {
                dp[b] = max(dp[b], take[b]);
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};

int main() {
    Solution sol;

    int n, budget;
    cin >> n;

    vector<vector<int>> items(n, vector<int>(2));

    for (int i = 0; i < n; i++) {
        cin >> items[i][0] >> items[i][1];
    }

    cin >> budget;

    cout << sol.maximumSaleItems(items, budget) << endl;

    return 0;
}
