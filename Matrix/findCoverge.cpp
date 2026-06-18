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

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] == 0)
                {
                    for (int k = 0; k < 4; k++)
                    {
                        int ni = i + dx[k];
                        int nj = j + dy[k];

                        if (ni >= 0 && ni < n &&
                            nj >= 0 && nj < m &&
                            mat[ni][nj] == 1)
                        {
                            ans++;
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