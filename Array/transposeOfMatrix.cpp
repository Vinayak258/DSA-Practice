#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> transpose(vector<vector<int>> &mat)
    {
        int n = mat.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                swap(mat[i][j], mat[j][i]);
            }
        }
        return mat;
    }
};

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> mat(n, vector<int>(n));

    // Input matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> mat[i][j];
        }
    }

    Solution ob;
    vector<vector<int>> ans = ob.transpose(mat);

    // Output matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
