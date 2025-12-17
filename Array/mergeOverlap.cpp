#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> mergeOverlap(vector<vector<int>> &arr)
    {
        if (arr.empty())
            return {};

        // Sort intervals by starting time
        sort(arr.begin(), arr.end());

        vector<vector<int>> result;
        result.push_back(arr[0]);

        // Merge overlapping intervals
        for (int i = 1; i < arr.size(); i++)
        {
            if (arr[i][0] <= result.back()[1])
            {
                result.back()[1] = max(result.back()[1], arr[i][1]);
            }
            else
            {
                result.push_back(arr[i]);
            }
        }

        return result;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vector<vector<int>> arr(n, vector<int>(2));
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i][0] >> arr[i][1];
        }

        Solution obj;
        vector<vector<int>> ans = obj.mergeOverlap(arr);

        for (auto &interval : ans)
        {
            cout << interval[0] << " " << interval[1] << " ";
        }
        cout << endl;
    }
    return 0;
}
