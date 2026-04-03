#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> diagView(vector<vector<int>> mat)
    {
        int n = mat.size();
        vector<int> ans;

        // Traverse all anti-diagonals
        for (int d = 0; d <= 2 * n - 2; d++)
        {
            int rowStart = max(0, d - n + 1);
            int rowEnd = min(n - 1, d);

            for (int i = rowStart; i <= rowEnd; i++)
            {
                int j = d - i;
                ans.push_back(mat[i][j]);
            }
        }

        return ans;
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

    Solution obj;
    vector<int> result = obj.diagView(mat);

    // Print result
    for (int x : result)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}