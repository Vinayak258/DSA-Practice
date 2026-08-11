#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int missingInteger(vector<int> &nums)
    {
        int sum = nums[0];

        // Find sum of longest sequential prefix
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == nums[i - 1] + 1)
            {
                sum += nums[i];
            }
            else
            {
                break;
            }
        }

        // Find the smallest missing integer >= sum
        while (find(nums.begin(), nums.end(), sum) != nums.end())
        {
            sum++;
        }

        return sum;
    }
};

int main()
{
    int n;

    cout << "Enter the size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    Solution obj;

    int result = obj.missingInteger(nums);

    cout << "Smallest missing integer: " << result << endl;

    return 0;
}