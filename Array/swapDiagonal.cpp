#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void swapDiagonal(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int limit = min(n, n); // explicit use of min()

        for (int i = 0; i < limit; i++)
        {
            swap(mat[i][i], mat[i][n - 1 - i]);
        }
    }
};

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> mat(n, vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> mat[i][j];
        }
    }

    Solution obj;
    obj.swapDiagonal(mat);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
