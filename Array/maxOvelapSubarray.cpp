#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int overlapInt(vector<vector<int>> &arr)
    {
        vector<pair<int, int>> events;

        for (auto &it : arr)
        {
            int s = it[0];
            int e = it[1];
            events.push_back({s, 1});      // start of interval
            events.push_back({e + 1, -1}); // end (inclusive handling)
        }

        sort(events.begin(), events.end());

        int curr = 0, ans = 0;
        for (auto &e : events)
        {
            curr += e.second;
            ans = max(ans, curr);
        }
        return ans;
    }
};

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> arr(n, vector<int>(2));
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i][0] >> arr[i][1];
    }

    Solution obj;
    cout << obj.overlapInt(arr) << endl;

    return 0;
}
