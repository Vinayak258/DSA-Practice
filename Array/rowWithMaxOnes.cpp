#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int rowWithMax1s(vector<vector<int>> &arr)
    {
        int n = arr.size();
        int m = arr[0].size();

        int maxOnes = 0;
        int resultRow = -1;

        for (int i = 0; i < n; i++)
        {
            int low = 0, high = m - 1;
            int firstOne = -1;

            // Binary search to find first 1 in current row
            while (low <= high)
            {
                int mid = low + (high - low) / 2;
                if (arr[i][mid] == 1)
                {
                    firstOne = mid;
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }

            if (firstOne != -1)
            {
                int onesCount = m - firstOne;
                if (onesCount > maxOnes)
                {
                    maxOnes = onesCount;
                    resultRow = i;
                }
            }
        }

        return resultRow;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> arr(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    Solution obj;
    cout << obj.rowWithMax1s(arr);

    return 0;
}
