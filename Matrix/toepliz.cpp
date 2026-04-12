#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isToeplitz(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();

        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                if (mat[i][j] != mat[i - 1][j - 1])
                {
                    return false;
                }
            }
        }

        return true;
    }
};

int main()
{
    vector<vector<int>> mat = {
        {6, 7, 8},
        {4, 6, 7},
        {1, 4, 6}};

    Solution obj;

    if (obj.isToeplitz(mat))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}