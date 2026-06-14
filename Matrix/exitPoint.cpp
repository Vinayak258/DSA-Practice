#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> exitPoint(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();

        int i = 0, j = 0;
        int dir = 0; // 0=Right, 1=Down, 2=Left, 3=Up

        while (true)
        {
            if (mat[i][j] == 1)
            {
                dir = (dir + 1) % 4; // Turn clockwise
                mat[i][j] = 0;       // Update cell to 0
            }

            int ni = i, nj = j;

            if (dir == 0)
                nj++; // Right
            else if (dir == 1)
                ni++; // Down
            else if (dir == 2)
                nj--; // Left
            else
                ni--; // Up

            // If next position is outside matrix,
            // current cell is the exit point.
            if (ni < 0 || ni >= n || nj < 0 || nj >= m)
            {
                return {i, j};
            }

            i = ni;
            j = nj;
        }
    }
};

int main()
{
    int n, m;

    cout << "Enter number of rows and columns: ";
    cin >> n >> m;

    vector<vector<int>> mat(n, vector<int>(m));

    cout << "Enter matrix elements (0 or 1):\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mat[i][j];
        }
    }

    Solution obj;
    vector<int> ans = obj.exitPoint(mat);

    cout << "Exit Point: [" << ans[0] << ", " << ans[1] << "]\n";

    return 0;
}