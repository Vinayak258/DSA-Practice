#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> result;
    vector<int> current;

    void backtrack(vector<int> &nums, int start)
    {
        result.push_back(current);

        for (int i = start; i < nums.size(); i++)
        {
            current.push_back(nums[i]);
            backtrack(nums, i + 1);
            current.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int> &nums)
    {
        backtrack(nums, 0);
        return result;
    }
};

int main()
{
    Solution sol;

    // Input
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    // Generate subsets
    vector<vector<int>> ans = sol.subsets(nums);

    // Output
    cout << "All subsets:\n";
    for (auto &subset : ans)
    {
        cout << "[ ";
        for (int x : subset)
        {
            cout << x << " ";
        }
        cout << "]\n";
    }

    return 0;
}
