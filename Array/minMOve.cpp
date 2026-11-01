
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minMoves(vector<int> &nums)
    {
        int mn = *min_element(nums.begin(), nums.end());

        int moves = 0;

        for (int num : nums)
        {
            moves += num - mn;
        }

        return moves;
    }
};

int main()
{
    Solution obj;

    vector<int> nums = {1, 2, 3};

    cout << obj.minMoves(nums) << endl;

    return 0;
}
