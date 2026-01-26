#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void solve(int index, vector<int> &arr, vector<vector<int>> &ans)
    {
        if (index == arr.size())
        {
            ans.push_back(arr);
            return;
        }

        for (int i = index; i < arr.size(); i++)
        {
            swap(arr[index], arr[i]);
            solve(index + 1, arr, ans);
            swap(arr[index], arr[i]); // backtrack
        }
    }

    vector<vector<int>> permuteDist(vector<int> &arr)
    {
        vector<vector<int>> ans;
        solve(0, arr, ans);
        return ans;
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

    Solution obj;
    vector<vector<int>> result = obj.permuteDist(arr);

    // sorting as per GFG output format
    sort(result.begin(), result.end());

    for (auto &perm : result)
    {
        cout << "[";
        for (int i = 0; i < perm.size(); i++)
        {
            cout << perm[i];
            if (i != perm.size() - 1)
                cout << " ";
        }
        cout << "] ";
    }

    return 0;
}
