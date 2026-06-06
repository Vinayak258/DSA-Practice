#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution
{
public:
    vector<int> leftRightDifference(vector<int> &nums)
    {

        int n = nums.size();

        vector<int> answer(n);

        // Calculate total sum
        int totalSum = 0;

        for (int num : nums)
        {
            totalSum += num;
        }

        int leftSum = 0;

        // Calculate differences
        for (int i = 0; i < n; i++)
        {

            int rightSum = totalSum - leftSum - nums[i];

            answer[i] = abs(leftSum - rightSum);

            leftSum += nums[i];
        }

        return answer;
    }
};

int main()
{

    vector<int> nums = {10, 4, 8, 3};

    Solution obj;

    vector<int> result = obj.leftRightDifference(nums);

    cout << "Output: ";

    for (int x : result)
    {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}