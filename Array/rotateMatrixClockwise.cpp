#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Rotate matrix 90 degrees clockwise
    void rotate(vector<vector<int>> &mat)
    {
        int n = mat.size();
        vector<vector<int>> temp(n, vector<int>(n));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                temp[j][n - i - 1] = mat[i][j];
            }
        }

        mat = temp;
    }

    // Check if two matrices are equal
    bool isEqual(vector<vector<int>> &a, vector<vector<int>> &b)
    {
        return a == b;
    }

    bool findRotation(vector<vector<int>> &mat, vector<vector<int>> &target)
    {
        for (int i = 0; i < 4; i++)
        {
            if (isEqual(mat, target))
                return true;
            rotate(mat);
        }
        return false;
    }
};

int main()
{
    Solution obj;

    int n;
    cout << "Enter size of matrix (n): ";
    cin >> n;

    vector<vector<int>> mat(n, vector<int>(n));
    vector<vector<int>> target(n, vector<int>(n));

    cout << "Enter matrix mat:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> mat[i][j];
        }
    }

    cout << "Enter matrix target:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> target[i][j];
        }
    }

    if (obj.findRotation(mat, target))
    {
        cout << "True\n";
    }
    else
    {
        cout << "False\n";
    }

    return 0;
}