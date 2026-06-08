#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> pivotArray(vector<int> &nums, int pivot)
    {
        vector<int> less, equal, greater;

        // Divide elements into three groups
        for (int num : nums)
        {
            if (num < pivot)
                less.push_back(num);
            else if (num == pivot)
                equal.push_back(num);
            else
                greater.push_back(num);
        }

        // Combine all groups
        vector<int> result;

        result.insert(result.end(), less.begin(), less.end());
        result.insert(result.end(), equal.begin(), equal.end());
        result.insert(result.end(), greater.begin(), greater.end());

        return result;
    }
};

int main()
{
    Solution sol;

    vector<int> nums = {9, 12, 5, 10, 14, 3, 10};
    int pivot = 10;

    vector<int> ans = sol.pivotArray(nums, pivot);

    cout << "Partitioned Array: ";
    for (int x : ans)
    {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}