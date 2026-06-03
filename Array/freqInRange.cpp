#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> freqInRange(vector<int> &arr,
                            vector<vector<int>> &queries)
    {

        unordered_map<int, vector<int>> mp;

        // Store indices of each element
        for (int i = 0; i < arr.size(); i++)
        {
            mp[arr[i]].push_back(i);
        }

        vector<int> ans;

        for (auto &q : queries)
        {

            int l = q[0];
            int r = q[1];
            int x = q[2];

            // If x is not present
            if (mp.find(x) == mp.end())
            {
                ans.push_back(0);
                continue;
            }

            vector<int> &v = mp[x];

            // First index >= l
            auto left = lower_bound(v.begin(), v.end(), l);

            // First index > r
            auto right = upper_bound(v.begin(), v.end(), r);

            ans.push_back(right - left);
        }

        return ans;
    }
};

int main()
{

    vector<int> arr = {1, 2, 1, 3, 1, 2, 3};

    vector<vector<int>> queries = {
        {0, 4, 1},
        {2, 5, 2},
        {1, 6, 3},
        {0, 6, 5}};

    Solution obj;

    vector<int> ans = obj.freqInRange(arr, queries);

    cout << "Output: ";

    for (int x : ans)
    {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}