#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int findCoverage(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();

        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {

                if (mat[i][j] == 0)
                {

                    // Up
                    for (int r = i - 1; r >= 0; r--)
                    {
                        if (mat[r][j] == 1)
                        {
                            ans++;
                            break;
                        }
                    }

                    // Down
                    for (int r = i + 1; r < n; r++)
                    {
                        if (mat[r][j] == 1)
                        {
                            ans++;
                            break;
                        }
                    }

                    // Left
                    for (int c = j - 1; c >= 0; c--)
                    {
                        if (mat[i][c] == 1)
                        {
                            ans++;
                            break;
                        }
                    }

                    // Right
                    for (int c = j + 1; c < m; c++)
                    {
                        if (mat[i][c] == 1)
                        {
                            ans++;
                            break;
                        }
                    }
                }
            }
        }

        return ans;
    }
};
int main()
{
    int n, m;

    cout << "Enter number of rows and columns: ";
    cin >> n >> m;

    vector<vector<int>> mat(n, vector<int>(m));

    cout << "Enter the matrix elements (0 or 1):\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mat[i][j];
        }
    }

    Solution obj;
    cout << "Total Coverage: " << obj.findCoverage(mat) << endl;

    return 0;
}