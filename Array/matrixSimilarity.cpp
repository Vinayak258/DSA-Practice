#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool areSimilar(vector<vector<int>> &mat, int k)
    {
        int m = mat.size();
        int n = mat[0].size();

        k = k % n; // reduce unnecessary rotations

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {

                if (i % 2 == 0)
                {
                    // even row → left shift
                    if (mat[i][j] != mat[i][(j + k) % n])
                        return false;
                }
                else
                {
                    // odd row → right shift
                    if (mat[i][j] != mat[i][(j - k + n) % n])
                        return false;
                }
            }
        }
        return true;
    }
};

int main()
{
    int m, n, k;

    cout << "Enter rows and columns: ";
    cin >> m >> n;

    vector<vector<int>> mat(m, vector<int>(n));

    cout << "Enter matrix elements:\n";
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> mat[i][j];
        }
    }

    cout << "Enter k: ";
    cin >> k;

    Solution obj;
    bool result = obj.areSimilar(mat, k);

    if (result)
        cout << "true\n";
    else
        cout << "false\n";

    return 0;
}