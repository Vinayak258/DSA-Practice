#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<int> findMissingElements(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());

        vector<int> ans;

        for (int i = 1; i < nums.size(); i++)
        {
            for (int x = nums[i - 1] + 1; x < nums[i]; x++)
            {
                ans.push_back(x);
            }
        }

        return ans;
    }
};

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    Solution obj;
    vector<int> ans = obj.findMissingElements(nums);

    if (ans.empty())
    {
        cout << "No missing elements" << endl;
    }
    else
    {
        cout << "Missing elements: ";
        for (int x : ans)
        {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}