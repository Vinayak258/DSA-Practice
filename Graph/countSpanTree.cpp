#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to calculate determinant using Gaussian Elimination
    long long determinant(vector<vector<double>> mat, int n)
    {

        double det = 1.0;

        for (int i = 0; i < n; i++)
        {

            // Find pivot row
            int pivot = i;

            for (int j = i; j < n; j++)
            {
                if (abs(mat[j][i]) > abs(mat[pivot][i]))
                {
                    pivot = j;
                }
            }

            // If pivot becomes 0
            if (abs(mat[pivot][i]) < 1e-9)
                return 0;

            // Swap rows if needed
            if (pivot != i)
            {
                swap(mat[pivot], mat[i]);
                det *= -1;
            }

            det *= mat[i][i];

            // Eliminate below rows
            for (int j = i + 1; j < n; j++)
            {

                double factor = mat[j][i] / mat[i][i];

                for (int k = i; k < n; k++)
                {
                    mat[j][k] -= factor * mat[i][k];
                }
            }
        }

        return round(det);
    }

    int countSpanTree(int n, vector<vector<int>> &edges)
    {

        // Special case
        if (n == 1)
            return 1;

        // Build Laplacian Matrix
        vector<vector<double>> lap(n, vector<double>(n, 0));

        for (auto &e : edges)
        {

            int u = e[0];
            int v = e[1];

            lap[u][u]++;
            lap[v][v]++;

            lap[u][v]--;
            lap[v][u]--;
        }

        // Create Cofactor Matrix
        vector<vector<double>> cofactor(n - 1,
                                        vector<double>(n - 1));

        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - 1; j++)
            {
                cofactor[i][j] = lap[i][j];
            }
        }

        // Determinant of cofactor matrix
        return (int)determinant(cofactor, n - 1);
    }
};

int main()
{

    int n, m;

    cin >> n >> m;

    vector<vector<int>> edges;

    for (int i = 0; i < m; i++)
    {

        int u, v;
        cin >> u >> v;

        edges.push_back({u, v});
    }

    Solution obj;

    cout << obj.countSpanTree(n, edges) << endl;

    return 0;
}