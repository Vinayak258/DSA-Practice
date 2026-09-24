
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int smallestIndex(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            int x = nums[i];
            int sum = 0;

            // Calculate digit sum
            while (x > 0)
            {
                sum += x % 10;
                x /= 10;
            }

            // Check condition
            if (sum == i)
            {
                return i;
            }
        }

        return -1;
    }
};

int main()
{

    vector<int> arr = {1, 85, 9, 9, 6, 4, 6, 8, 2, 3};

    Solution s1;
    cout << s1.smallestIndex(arr);
}