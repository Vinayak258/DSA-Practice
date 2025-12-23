#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> cntInRange(vector<int> &arr, vector<vector<int>> &queries)
    {
        sort(arr.begin(), arr.end());

        vector<int> ans;
        for (auto &q : queries)
        {
            int a = q[0], b = q[1];
            ans.push_back(
                upper_bound(arr.begin(), arr.end(), b) -
                lower_bound(arr.begin(), arr.end(), a));
        }
        return ans;
    }
};

int main()
{
    int n, q;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cin >> q;
    vector<vector<int>> queries(q, vector<int>(2));
    for (int i = 0; i < q; i++)
    {
        cin >> queries[i][0] >> queries[i][1];
    }

    Solution obj;
    vector<int> result = obj.cntInRange(arr, queries);

    for (int x : result)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
