#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> countXInRange(vector<int> &arr, vector<vector<int>> &queries)
    {
        vector<int> result;

        for (auto &q : queries)
        {
            int l = q[0];
            int r = q[1];
            int x = q[2];

            auto first = lower_bound(arr.begin() + l, arr.begin() + r + 1, x);

            if (first == arr.begin() + r + 1 || *first != x)
            {
                result.push_back(0);
                continue;
            }

            auto last = upper_bound(arr.begin() + l, arr.begin() + r + 1, x);
            result.push_back(last - first);
        }

        return result;
    }
};

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int q;
    cin >> q;

    vector<vector<int>> queries(q, vector<int>(3));
    for (int i = 0; i < q; i++)
    {
        cin >> queries[i][0] >> queries[i][1] >> queries[i][2];
    }

    Solution obj;
    vector<int> ans = obj.countXInRange(arr, queries);

    for (int x : ans)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
