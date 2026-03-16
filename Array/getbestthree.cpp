#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> getBiggestThree(vector<vector<int>> &grid)
    {

        int m = grid.size();
        int n = grid[0].size();

        set<int, greater<int>> st;

        for (int r = 0; r < m; r++)
        {
            for (int c = 0; c < n; c++)
            {

                // size 0 rhombus
                st.insert(grid[r][c]);

                for (int k = 1;; k++)
                {

                    if (r + 2 * k >= m || c - k < 0 || c + k >= n)
                        break;

                    int sum = 0;
                    int x = r, y = c;

                    // top -> right
                    for (int i = 0; i < k; i++)
                        sum += grid[x + i][y + i];

                    // right -> bottom
                    for (int i = 0; i < k; i++)
                        sum += grid[x + k + i][y + k - i];

                    // bottom -> left
                    for (int i = 0; i < k; i++)
                        sum += grid[x + 2 * k - i][y - i];

                    // left -> top
                    for (int i = 0; i < k; i++)
                        sum += grid[x + k - i][y - k + i];

                    st.insert(sum);
                }
            }
        }

        vector<int> ans;

        for (auto x : st)
        {
            ans.push_back(x);
            if (ans.size() == 3)
                break;
        }

        return ans;
    }
};

int main()
{

    int m, n;
    cin >> m >> n;

    vector<vector<int>> grid(m, vector<int>(n));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }

    Solution obj;

    vector<int> result = obj.getBiggestThree(grid);

    for (int x : result)
        cout << x << " ";

    cout << endl;

    return 0;
}