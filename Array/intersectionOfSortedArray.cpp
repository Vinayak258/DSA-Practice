#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> intersection(vector<int> &a, vector<int> &b)
    {
        vector<int> ans;
        int i = 0, j = 0;

        while (i < a.size() && j < b.size())
        {
            if (a[i] < b[j])
            {
                i++;
            }
            else if (a[i] > b[j])
            {
                j++;
            }
            else
            {
                // Add only distinct common elements
                if (ans.empty() || ans.back() != a[i])
                {
                    ans.push_back(a[i]);
                }
                i++;
                j++;
            }
        }

        return ans;
    }
};

int main()
{
    vector<int> a = {1, 1, 2, 2, 2, 4};
    vector<int> b = {2, 2, 4, 4};

    Solution obj;
    vector<int> result = obj.intersection(a, b);

    for (int x : result)
    {
        cout << x << " ";
    }

    return 0;
}