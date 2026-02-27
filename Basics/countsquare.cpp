```cpp
#include <vector>
    using namespace std;

class Solution
{
public:
    int countSquare(vector<vector<int>> &mat, int x)
    {
        int n = mat.size();
        int m = mat[0].size();

        // Prefix sum matrix
        vector<vector<long long>> ps(n + 1, vector<long long>(m + 1, 0));

        // Build prefix sums
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                ps[i][j] = mat[i - 1][j - 1] + ps[i - 1][j] + ps[i][j - 1] - ps[i - 1][j - 1];
            }
        }

        int count = 0;

        // Try every top-left corner
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {

                int maxLen = min(n - i, m - j);

                // Try all square sizes
                for (int len = 1; len <= maxLen; len++)
                {
                    int r1 = i;
                    int c1 = j;
                    int r2 = i + len;
                    int c2 = j + len;

                    long long sum = ps[r2][c2] - ps[r1][c2] - ps[r2][c1] + ps[r1][c1];

                    if (sum == x)
                        count++;
                }
            }
        }

        return count;
    }
};
```
