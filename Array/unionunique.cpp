```cpp
#include <bits/stdc++.h>
    using namespace std;

class Solution
{
public:
    vector<int> findUnion(vector<int> &a, vector<int> &b)
    {
        vector<int> ans;
        map<int, int> maap;

        for (int i = 0; i < a.size(); i++)
        {
            maap[a[i]]++;
        }

        for (int i = 0; i < b.size(); i++)
        {
            maap[b[i]]++;
        }

        for (auto it = maap.begin(); it != maap.end(); it++)
        {
            ans.push_back(it->first);
        }

        return ans;
    }
};

int main()
{
    int n, m;

    // input size of first array
    cout << "Enter size of first array: ";
    cin >> n;
    vector<int> a(n);

    cout << "Enter elements of first array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // input size of second array
    cout << "Enter size of second array: ";
    cin >> m;
    vector<int> b(m);

    cout << "Enter elements of second array: ";
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }

    Solution sol;
    vector<int> result = sol.findUnion(a, b);

    cout << "Union of arrays: ";
    for (int x : result)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
```
