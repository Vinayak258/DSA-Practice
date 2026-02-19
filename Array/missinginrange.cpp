#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> missingRange(vector<int> &arr, int low, int high)
    {
        vector<bool> present(high - low + 1, false);

        // mark numbers present in the range
        for (int x : arr)
        {
            if (x >= low && x <= high)
            {
                present[x - low] = true;
            }
        }

        vector<int> ans;
        for (int i = 0; i < present.size(); i++)
        {
            if (!present[i])
            {
                ans.push_back(low + i);
            }
        }
        return ans;
    }
};

int main()
{
    vector<int> arr = {10, 12, 11, 15};
    int low = 10;
    int high = 15;

    Solution obj;
    vector<int> result = obj.missingRange(arr, low, high);

    cout << "Missing numbers: ";
    for (int x : result)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
