#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> constructList(vector<vector<int>> &queries)
    {
        vector<int> ans;
        int xr = 0;

        // Process queries in reverse
        for (int i = (int)queries.size() - 1; i >= 0; i--)
        {
            int type = queries[i][0];
            int x = queries[i][1];

            if (type == 1)
            {
                xr ^= x;
            }
            else
            {
                ans.push_back(x ^ xr);
            }
        }

        // Initial element 0 after all XOR operations
        ans.push_back(xr);

        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    int q;
    cin >> q;

    vector<vector<int>> queries(q, vector<int>(2));

    for (int i = 0; i < q; i++)
    {
        cin >> queries[i][0] >> queries[i][1];
    }

    Solution obj;
    vector<int> result = obj.constructList(queries);

    for (int x : result)
    {
        cout << x << " ";
    }
    cout << "\n";

    return 0;
}