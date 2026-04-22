#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findMean(vector<int> &arr, vector<vector<int>> &queries)
    {
        int n = arr.size();

        // Prefix sum array
        vector<long long> prefix(n);
        prefix[0] = arr[0];

        for (int i = 1; i < n; i++)
        {
            prefix[i] = prefix[i - 1] + arr[i];
        }

        vector<int> result;

        for (auto &q : queries)
        {
            int l = q[0];
            int r = q[1];

            long long sum = prefix[r];
            if (l > 0)
            {
                sum -= prefix[l - 1];
            }

            int length = r - l + 1;
            result.push_back(sum / length); // floor division
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

    vector<vector<int>> queries(q, vector<int>(2));
    for (int i = 0; i < q; i++)
    {
        cin >> queries[i][0] >> queries[i][1];
    }

    Solution obj;
    vector<int> ans = obj.findMean(arr, queries);

    for (int x : ans)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}