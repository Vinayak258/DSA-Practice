#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();

        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Base case: only one pile
        for (int i = 0; i < n; i++) {
            dp[i][i] = piles[i];
        }

        // Fill DP table
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;

                dp[i][j] = max(
                    piles[i] - dp[i + 1][j],
                    piles[j] - dp[i][j - 1]
                );
            }
        }

        return dp[0][n - 1] > 0;
    }
};

int main() {
    int n;
    cout << "Enter number of piles: ";
    cin >> n;

    vector<int> piles(n);

    cout << "Enter the stones in each pile: ";
    for (int i = 0; i < n; i++) {
        cin >> piles[i];
    }

    Solution obj;

    if (obj.stoneGame(piles))
        cout << "Alice wins!" << endl;
    else
        cout << "Bob wins!" << endl;

    return 0;
}