#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution
{
public:
    int minMoves2(vector<int> &nums)
    {
        // Sort the array to find the median
        sort(nums.begin(), nums.end());

        int median = nums[nums.size() / 2];
        int moves = 0;

        // Calculate the sum of absolute differences from the median
        for (int num : nums)
        {
            moves += abs(num - median);
        }

        return moves;
    }
};

int main()
{
    Solution solver;

    // Test Case 1
    vector<int> nums1 = {1, 2, 3};
    cout << "Test Case 1: [1, 2, 3]" << endl;
    cout << "Minimum Moves: " << solver.minMoves2(nums1) << " (Expected: 2)" << endl;
    cout << "-----------------------------------" << endl;

    // Test Case 2
    vector<int> nums2 = {1, 10, 2, 9};
    cout << "Test Case 2: [1, 10, 2, 9]" << endl;
    cout << "Minimum Moves: " << solver.minMoves2(nums2) << " (Expected: 16)" << endl;
    cout << "-----------------------------------" << endl;

    return 0;
}