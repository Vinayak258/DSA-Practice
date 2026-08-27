#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxArea(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();

        vector<int> height(m, 0);
        int ans = 0;

        for (int i = 0; i < n; i++)
        {

            // Build histogram heights
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] == 1)
                    height[j]++;
                else
                    height[j] = 0;
            }

            // Copy heights because original height[]
            // must remain unchanged
            vector<int> temp = height;

            // Arrange columns optimally
            sort(temp.begin(), temp.end(), greater<int>());

            // Calculate maximum rectangle area
            for (int j = 0; j < m; j++)
            {
                int width = j + 1;
                int area = temp[j] * width;

                ans = max(ans, area);
            }
        }

        return ans;
    }
};

int main()
{
    int n, m;

    // Input number of rows and columns
    cin >> n >> m;

    vector<vector<int>> mat(n, vector<int>(m));

    // Input matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mat[i][j];
        }
    }

    Solution obj;

    // Calculate and print answer
    cout << obj.maxArea(mat) << endl;

    return 0;
}