#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> smallestDiff(vector<int> &a, vector<int> &b, vector<int> &c)
    {
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        sort(c.begin(), c.end());

        int i = 0, j = 0, k = 0;
        int mini = INT_MAX;
        int sum = INT_MAX;
        vector<int> v;

        while (i < a.size() && j < b.size() && k < c.size())
        {
            int x = a[i], y = b[j], z = c[k];

            int cmin = min({x, y, z});
            int cmax = max({x, y, z});
            int diff = cmax - cmin;

            if (diff < mini || (diff == mini && x + y + z < sum))
            {
                mini = diff;
                sum = x + y + z;
                v = {x, y, z};
            }

            if (cmin == x)
                i++;
            else if (cmin == y)
                j++;
            else
                k++;
        }

        sort(v.begin(), v.end(), greater<int>()); // remove if not required
        return v;
    }
};

int main()
{
    Solution obj;

    vector<int> a = {1, 4, 10};
    vector<int> b = {2, 15, 20};
    vector<int> c = {10, 12};

    vector<int> result = obj.smallestDiff(a, b, c);

    cout << "Result: ";
    for (int x : result)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
