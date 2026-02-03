#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool isTrionic(vector<int> &nums)
    {

        int n = nums.size();
        if (n < 3)
            return false;

        int i = 1;
        while (i < n && nums[i] > nums[i - 1])
        {
            i++;
        }

        if (i == 1 || i == n)
            return false;

        while (i < n && nums[i] < nums[i - 1])
        {
            i++;
        }
        if (i == n)
            return false;

        while (i < n && nums[i] > nums[i - 1])
        {
            i++;
        }

        return i == n;
    }
};

int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    Solution obj;
    if (obj.isTrionic(nums))
    {
        std::cout << "True" << std::endl;
    }
    else
    {
        std::cout << "False" << std::endl;
    }

    return 0;
}