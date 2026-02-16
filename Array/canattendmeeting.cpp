#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canAttend(vector<vector<int>> &arr)
    {
        // Sort meetings by start time
        sort(arr.begin(), arr.end());

        // Check for overlaps
        for (int i = 1; i < arr.size(); i++)
        {
            if (arr[i][0] < arr[i - 1][1])
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution obj;

    // Example input
    vector<vector<int>> meetings = {{1, 4}, {10, 15}, {7, 10}};

    bool result = obj.canAttend(meetings);

    if (result)
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}
