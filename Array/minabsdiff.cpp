#include <iostream>
#include <vector>
#include <set>
#include <climits>
using namespace std;

class Solution
{
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>> &grid, int k)
    {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> ans(m - k + 1, vector<int>(n - k + 1));

        for (int i = 0; i <= m - k; ++i)
        {
            for (int j = 0; j <= n - k; ++j)
            {

                set<int> st;

                // Collect elements
                for (int r = i; r < i + k; ++r)
                {
                    for (int c = j; c < j + k; ++c)
                    {
                        st.insert(grid[r][c]);
                    }
                }

                // If only one distinct value
                if (st.size() <= 1)
                {
                    ans[i][j] = 0;
                    continue;
                }

                int minDiff = INT_MAX;

                auto it = st.begin();
                auto prev = it;
                ++it;

                while (it != st.end())
                {
                    minDiff = min(minDiff, *it - *prev);
                    prev = it;
                    ++it;
                }

                ans[i][j] = minDiff;
            }
        }

        return ans;
    }
};

int main()
{
    Solution sol;

    // Example input
    vector<vector<int>> grid = {
        {1, -2, 3},
        {2, 3, 5}};
    int k = 2;

    vector<vector<int>> result = sol.minAbsDiff(grid, k);

    // Print output
    cout << "Output:\n";
    for (auto &row : result)
    {
        for (auto &val : row)
        {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}